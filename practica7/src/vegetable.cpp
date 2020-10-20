#ifndef VEGETABLE_CPP  
#define VEGETABLE_CPP 

#include "../include/vegetable.hpp"

vegetable::vegetable(std::string _name, float _weight, float _priceweight, int _stock) : product(_name, _priceweight, _stock){
    weight = _weight;
    date = time(0);
    price_due_weight = _priceweight;
}

vegetable::~vegetable(){
    //Nothing to destroy
}

void vegetable::setWeight(float _weight){
    weight = _weight;
    date = time(0);
}

time_t vegetable::getDate(){
    return date;
}

void vegetable::updateDate(){
    date = time(0);
}

void vegetable::changePriceWeight(float _price){
    price_due_weight = _price;
    date = time(0);
}

float vegetable::getPriceWeight(){
    return price_due_weight;
}

float vegetable::getCost(float _sellWeight){
    return _sellWeight*price_due_weight;
}


#endif // VEGETABLE_CPP