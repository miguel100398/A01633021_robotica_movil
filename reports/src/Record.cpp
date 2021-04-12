#ifndef RECORD_CPP
#define RECORD_CPP 

#include "../include/Record.hpp"

/////////////////////////Constructors///////////////////////////////////////////////////////////////
Record::Record(){
    this->year       = 0;
    this->region     = "No Region";
    this->subRegion  ="No SubRegion";
    this->animalType = "No Animal Type";
    this->numFarms   = 0;
    this->numAnimals = 0;
    //std::cout<<"New record" << std::endl;
}

Record::Record(int year, std::string region, std::string subRegion, std::string animalType, int numFarms, int numAnimals){
    this->year = year;
    this->region = region;
    this->subRegion = subRegion;
    this->animalType = animalType;
    this->numFarms = numFarms;
    this->numAnimals = numAnimals;
    //std::cout << "New record" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////Destructor//////////////////////////////////////////////////////////////////////
Record::~Record(){
    //Nothing to do here
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////Setters//////////////////////////////////////////////////////////////////////////
void Record::set_year(int year){
    this->year = year;
}
void Record::set_region(std::string region){
    this->region = region;
}
void Record::set_subRegion(std::string subRegion){
    this->subRegion = subRegion;
}
void Record::set_animalType(std::string animalType){
    this->animalType = animalType;
}
void Record::set_numFarms(int numFarms){
    this->numFarms = numFarms;
}
void Record::set_numAnimals(int numAnimals){
    this->numAnimals = numAnimals;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////Getters//////////////////////////////////////////////////////////////////////////
int Record::get_year(){
    return this->year;
}
std::string Record::get_region(){
    return this->region;
}
std::string Record::get_subRegion(){
    return this->subRegion;
}
std::string Record::get_animalType(){
    return this->animalType;
}
int Record::get_numFarms(){
    return this->numFarms;
}
int Record::get_numAnimals(){
    return this->numAnimals;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////Methods////////////////////////////////////////////////////////////////////////////
std::string Record::toString(){
    std::stringstream ss;
    ss << "year:       " << this->year       << std::endl;
    ss << "region:     " << this->region     << std::endl;
    ss << "subRegion:  " << this->subRegion  << std::endl;
    ss << "animalType: " << this->animalType << std::endl;
    ss << "numFarms:   " << this->numFarms   << std::endl;
    ss << "numAnimals: " << this->numAnimals << std::endl;
    return ss.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif //RECORD_CPP