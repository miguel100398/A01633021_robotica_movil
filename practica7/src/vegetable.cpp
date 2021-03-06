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

float vegetable::getWeight(){
    return weight;
}

time_t* vegetable::getDate(){
    return &date;
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

void vegetable::changeName(std::string _name){
    product::changeName(_name);
    date = time(0);
}

void vegetable::changeCost(float _cost){
    product::changeCost(_cost);
    date = time(0);
}

bool vegetable::sellProduct(){
    date = time(0);
    return product::sellProduct();
}

void vegetable::addStock(int add_stock){
    product::addStock(add_stock);
    date = time(0);
}


#endif // VEGETABLE_CPP