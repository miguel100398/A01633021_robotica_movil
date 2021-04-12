#ifndef REPORTGENERATOR_CPP
#define REPORTGENERATOR_CPP

#include "../include/ReportGenerator.hpp"

//Default data file
std::string ReportGenerator::data_file = "../data/farms.dat";
std::vector<Record*> ReportGenerator::records;
Map<int> ReportGenerator::year_map;
Map<std::string> ReportGenerator::region_map;
Map<std::string> ReportGenerator::animal_map;

ReportGenerator::ReportGenerator(){
    //Nothing to do here
}

bool ReportGenerator::loadRecords(){
    Record* record;
    std::fstream fs;
    std::string line;
    int year;
    std::string region;
    std::string subRegion;
    std::string animalType;
    int numFarms;
    int numAnimals;
    //Open file
    fs.open(data_file.c_str());
    //Check if open
    if (!fs.is_open()){
        std::cout << "Error, Can't open file to read data, file: " << data_file << std::endl;
        return false; 
    }
    //Read file
    //Get lines
    while ( std::getline(fs, line)){
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        //Get tokens from line
        while( std::getline(ss, token, ' ')){
            //Add token to vector
            tokens.push_back(token);
        }
        //Get elements from tokens
        std::stringstream(tokens[0]) >> year;
        region = tokens[1];
        subRegion = tokens[2];
        animalType = tokens[3];
        std::stringstream(tokens[4]) >> numFarms;
        std::stringstream(tokens[5]) >> numAnimals;
        tokens.clear();
        //Create new Record
        record = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
        //Add new record to record collection
        records.push_back(record);
        //Add record to maps
        year_map.add(record->get_year(), record);
        region_map.add(record->get_region(), record);
        animal_map.add(record->get_animalType(), record);
    }
    //Close file
    fs.close();
    return true;

}

void ReportGenerator::cleanRecords(){
    for(int i=0; i<records.size(); i++){
        delete records[i];
    }
    records.clear();
}

void ReportGenerator::set_data_file(std::string file){
    data_file = file;
}

std::string ReportGenerator::get_data_file(){
    return data_file;
}

void ReportGenerator::set_width_column(int width){
    width_column = width;
}

int ReportGenerator::get_width_column(){
    return width_column;
}

void ReportGenerator::set_precision(int precisio){
    this->precision = precision;
}

int ReportGenerator::get_precision(){
    return precision;
}

void ReportGenerator::set_write_file(std::string file){
    write_file = file;
}

std::string ReportGenerator::get_write_file(){
    return write_file;
}

#endif //REPORTGENERATOR_CPP