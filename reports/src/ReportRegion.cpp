#ifndef REPORTREGION_CPP
#define REPORTREGION_CPP

#include "../include/ReportRegion.hpp"

ReportRegion::ReportRegion(){
    //Default write file
    write_file = "../data/ReportRegion.txt";
    //Default width column
    width_column = 15;
    //Default precision
    precision = 3;
    //Create Compare behaviour
    compare = new DescBehaviour<float>();
    //Create report Data
    reportdata = new ReportData<float>(compare);
}

ReportRegion::ReportRegion(std::string file, int width_column, int precision){
    write_file = file;
    this->width_column = width_column;
    this->precision = precision;
    //Create Compare behaviour
    compare = new DescBehaviour<float>();
    //Create report Data
    reportdata = new ReportData<float>(compare);
}

ReportRegion::~ReportRegion(){
    delete reportdata;
    delete compare;
}


void ReportRegion::compute(){
    Record* record;
    std::vector<Record*> records_region;
    std::vector<std::string> regions;
    std::vector<std::string> animals;
    std::string animal;
    
    //Get Records from region
    regions = region_map.get_keys();
    animals = animal_map.get_keys();
    //int animals_region[regions.size()][animals.size()] = {};
    //int total_animals[animals.size()] = {};
    int** animals_region = new int*[regions.size()];
    for (int i=0; i<regions.size(); i++){
        animals_region[i] = new int[animals.size()];
    }
    int* total_animals = new int[animals.size()];
    int total_all_animals = 0;
    
    //Count animals
    for (int i=0; i<region_map.get_size(); i++){
        //Exclude Canada
        if (regions[i] != "CAN"){
            records_region = region_map[regions[i]];
            for (int j=0; j<records_region.size(); j++){
                record = records_region[j];
                //Only get records from region All and year 2016
                if ((record->get_subRegion() == "All") && (record->get_year() == 2016)){
                    animal = record->get_animalType();
                    for (int k=0; k<animals.size(); k++){
                        if (animal == animals[k]){
                            animals_region[i][k] = record->get_numAnimals();
                            total_animals[k] += record->get_numAnimals();
                            total_all_animals += record->get_numAnimals();
                            break;
                        }
                    }
                }
            }   
        }
    }
    

    //Add to ReportData
    for (int i=0; i<region_map.get_size(); i++){
        float* percentages = new float[animals.size()];
        float total_percentage = 0;
        int all_animals_region = 0;
        //Exclude Canada
        if (regions[i] != "CAN"){
            for (int j=0; j<animals.size(); j++){
                if (total_animals[j] != 0){
                    percentages[j] = ((float)animals_region[i][j] / (float)total_animals[j]) * 100;
                } else {
                    percentages[j] = 0.0;
                }
                all_animals_region += animals_region[i][j];
            }
            total_percentage = ((float)all_animals_region / (float)total_all_animals) * 100;
            formatData(regions[i], percentages,  total_percentage);
        }
        delete[] percentages;
    }
    

    delete[] total_animals;
    for (int i=0; i<regions.size(); i++){
        delete[] animals_region[i];
    }
    delete[] animals_region;

}

void ReportRegion::formatData(std::string region, float percentages[], float total_percentage){
    std::stringstream data;
    data << std::left << std::setw(width_column) << std::setfill(' ') << region;
    std::stringstream tmp_final;
    for (int i=0; i<animal_map.get_size(); i++){
        std::stringstream tmp;
        tmp << std::fixed << std::setprecision(precision) << percentages[i] << "%";
        data << std::left << std::setw(width_column) << std::setfill(' ') << tmp.str();
    }
    tmp_final << std::fixed << std::setprecision(precision) << total_percentage << "%";
    data << std::left << std::setw(width_column) << std::setfill(' ') << tmp_final.str(); //<< "%";
    reportdata->add(total_percentage, data.str());
    

}

bool ReportRegion::printReport(){
    std::stringstream header;
    std::vector<std::string> animals;
    std::ofstream file;
    animals = animal_map.get_keys();
    //Format header
    header << std::left << std::setw(width_column) << std::setfill(' ') << "region";
    for (int i=0; i<animal_map.get_size(); i++){
        header << std::left << std::setw(width_column) << std::setfill(' ') << animals[i];
    }
    header << std::left << std::setw(width_column) << std::setfill(' ') << "total";
    header << std::endl;
    //Print to console and file

    //Open file
    file.open(write_file.c_str());

    //Check if file was opende
    if (!file.is_open()){
        std::cout << "Error, Can't open file to print report" << std::endl;
        return false;
    }

    //Print header
    std::cout << header.str();
    file << header.str();

    //Print data;
    std::cout << *reportdata;
    file << *reportdata;

    //Close file
    file.close();
    return true;



}

#endif //REPORTREGION_CPP