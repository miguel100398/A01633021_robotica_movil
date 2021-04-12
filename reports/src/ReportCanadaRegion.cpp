#ifndef REPORTCANADAREGION_CPP
#define REPORTCANADAREGION_CPP

#include "../include/ReportCanadaRegion.hpp"

ReportCanadaRegion::ReportCanadaRegion(){
    //Default write file
    write_file = "../data/ReportCanadaRegion.txt";
    //Default width column
    width_column = 15;
    //Default precision
    precision = 3;
    //Create Compare behaviour
    compare = new AscBehaviour<float>();
    //Create report Data
    reportdata = new ReportData<float>(compare);
}

ReportCanadaRegion::ReportCanadaRegion(std::string file, int width_column, int precision){
    write_file = file;
    this->width_column = width_column;
    this->precision = precision;
    //Create Compare behaviour
    compare = new AscBehaviour<float>();
    //Create report Data
    reportdata = new ReportData<float>(compare);
}

ReportCanadaRegion::~ReportCanadaRegion(){
    delete reportdata;
    delete compare;
}

void ReportCanadaRegion::compute(){
    std::vector<std::string> animals;
    std::vector<int> years;
    std::vector<Record*> records_year;
    Record* record;
    std::string animal;
    int num_animals;
    int total_animals_2011 = 0;
    int total_animals_2016 = 0;
    int total_animals = 0;
    int* type_animals_2011;
    int* type_animals_2016;

    

    years   = year_map.get_keys(); 
    animals = animal_map.get_keys();

    type_animals_2011 = new int[animals.size()];
    type_animals_2016 = new int[animals.size()];
     for (int i=0; i<animals.size(); i++){
        type_animals_2011[i] = 0;
        type_animals_2016[i] = 0;
    }

    //Count animals 2011
    records_year = year_map[2011];
    for (int i=0; i<records_year.size(); i++){
        //Only Canada
        record = records_year[i];
        if (record->get_region() == "CAN"){
            animal = record->get_animalType();
            for (int k=0; k<animals.size(); k++){
                if (animal == animals[k]){
                    num_animals = record->get_numAnimals();
                    total_animals_2011 += num_animals;
                    total_animals      += num_animals;
                    type_animals_2011[k] += num_animals;
                    break;
                }
            }
        }
    }

    //Count animals 2016
    records_year = year_map[2016];
    for (int i=0; i<records_year.size(); i++){
        //Only Canada
        record = records_year[i];
        if (record->get_region() == "CAN"){
            animal = record->get_animalType();
            for (int k=0; k<animals.size(); k++){
                if (animal == animals[k]){
                    num_animals = record->get_numAnimals();
                    total_animals_2016 += num_animals;
                    total_animals      += num_animals;
                    type_animals_2016[k] += num_animals;
                    break;
                }
            }
        }
    }

    //Add to ReportData
    for (int i=0; i<animals.size(); i++){
        float percentage_2011;
        float percentage_2016;
        float change_percentage;
        animal = animals[i];
        if (total_animals_2011 != 0){
            percentage_2011 = ((float)type_animals_2011[i] / (float)total_animals_2011) * 100;
        } else {
            percentage_2011 = 0;
        }
        if (total_animals_2016 != 0){
            percentage_2016 = ((float)type_animals_2016[i] / (float)total_animals_2016) * 100;
        } else {
            percentage_2016 = 0;
        }
        change_percentage = percentage_2016 - percentage_2011;
        formatData(animal, percentage_2011, percentage_2016, change_percentage);
    }

    delete[] type_animals_2011;
    delete[] type_animals_2016;

}

void ReportCanadaRegion::formatData(std::string animal, float percentage_2011, float percentage_2016, float change_percentage){
    std::stringstream data;
    data << std::left << std::setw(width_column) << std::setfill(' ') << animal;
    std::stringstream tmp_2011;
    std::stringstream tmp_2016;
    std::stringstream tmp_change;
   
    tmp_2011 << std::fixed << std::setprecision(precision) << percentage_2011 << "%";
    data << std::left << std::setw(width_column) << std::setfill(' ') << tmp_2011.str();
    tmp_2016 << std::fixed << std::setprecision(precision) << percentage_2016 << "%";
    data << std::left << std::setw(width_column) << std::setfill(' ') << tmp_2016.str();
    tmp_change << std::fixed << std::setprecision(precision) << change_percentage << "%";
    data << std::left << std::setw(width_column) << std::setfill(' ') << tmp_change.str();

    reportdata->add(change_percentage, data.str());
}

bool ReportCanadaRegion::printReport(){
    std::stringstream header;
    std::vector<std::string> animals;
    std::ofstream file;
    animals = animal_map.get_keys();
    //Format header
    header << std::left << std::setw(width_column) << std::setfill(' ') << "animal";
    header << std::left << std::setw(width_column) << std::setfill(' ') << "2011";
    header << std::left << std::setw(width_column) << std::setfill(' ') << "2016";
    header << std::left << std::setw(width_column) << std::setfill(' ') << "change 2011-2016";
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

#endif //REPORTCANADAREGION_CPP