#ifndef DRINK_CPP  
#define DRINK_CPP 

#include "../include/drink.hpp"

drink::drink(std::string _name, float _cost, int _stock, float _liters, time_t _expiry, float _density) : product(_name, _cost, _stock){
    liters = _liters;
    dateExpiry = _expiry;
    density = _density;
}

drink::~drink(){
    //Nothing to destroy
}

void drink::setLiters(float _liters){
    liters = _liters;
}

float drink::getLitters(){
    return liters;
}

void drink::addDateExpiry(time_t _date){
    dateExpiry = _date;
}

time_t drink::getDateExpiry(){
    return dateExpiry;
}

void drink::addDensity(float _density){
    density = _density;
}

float drink::getDensity(){
    return density;
}

float drink::getCost(){
    return liters*density*cost;
}

#endif //DRINK_CPP