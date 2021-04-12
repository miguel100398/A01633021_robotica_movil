#ifndef REPORTHORSES_CPP
#define REPORTHORSES_CPP

#include "../include/ReportHorses.hpp"

ReportHorses::ReportHorses(){
    //Default write file
    write_file = "../data/ReportRegion.txt";
    //Default width column
    width_column = 15;
    //Default precision
    precision = 3;
    //Create Compare behaviour
    compare = new DescBehaviour<int>();
    //Create report Data
    reportdata = new ReportData<int>(compare);
}

ReportHorses::ReportHorses(std::string file, int width_column, int precision){
    write_file = file;
    this->width_column = width_column;
    this->precision = precision;
    //Create Compare behaviour
    compare = new DescBehaviour<int>();
    //Create report Data
    reportdata = new ReportData<int>(compare);
}

ReportHorses::~ReportHorses(){
    delete reportdata;
    delete compare;
}

void ReportHorses::compute(){
    Record* record;
    std::vector<Record*> records_horse;
    std::vector<std::string> regions;
    std::string* high_subregion;
    std::string region;
    int num_animals;
    int* high_animal;

    high_subregion = new std::string[regions.size()];

    regions = region_map.get_keys();
    //Get records git horses and ponies
    records_horse = animal_map["Horses-Ponies"];

    high_subregion = new std::string[regions.size()];
    high_animal = new int[regions.size()];
    for (int i =0; i<regions.size(); i++){
        high_animal[i] = 0;
    }
    
    //Check regions
    for (int i=0; i<records_horse.size(); i++){
        record = records_horse[i];
        //Exclude Canada and subregion all
        region = record->get_region();

        if ((region != "CAN") && (record->get_subRegion() != "All")){
            for (int j=0; j<regions.size(); j++){
                if (region == regions[j]){
                    num_animals = record->get_numAnimals();
                    if (num_animals > high_animal[j]){      //Store highest number and subregion
                        high_animal[j] = num_animals;
                        high_subregion[j] = record->get_subRegion();
                    }
                    break;
                }
            }
        }
    }
    

    //Add to ReportData
    for (int i=0; i<regions.size(); i++){
        region = regions[i];
        //Exclude canada
        if (region != "CAN"){
            formatData(region, high_subregion[i], high_animal[i]);
        }
    }

    delete[] high_animal;
    delete[] high_subregion;

}

void ReportHorses::formatData(std::string region, std::string subregion, int numHorses){
    std::stringstream data;
    data << std::left << std::setw(width_column) << std::setfill(' ') << region;
    data << std::left << std::setw(width_column) << std::setfill(' ') << subregion;
    data << std::left << std::setw(width_column) << std::setfill(' ') << numHorses;


    reportdata->add(numHorses, data.str());
}

bool ReportHorses::printReport(){
    std::stringstream header;
    std::ofstream file;
    //Format header
    header << std::left << std::setw(width_column) << std::setfill(' ') << "region";
    header << std::left << std::setw(width_column) << std::setfill(' ') << "subRegion";
    header << std::left << std::setw(width_column) << std::setfill(' ') << "numAnimals";
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

#endif //REPORTHORSES_CPP