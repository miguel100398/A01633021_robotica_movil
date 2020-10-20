#ifndef PRODUCT_CPP  
#define PRODUCT_CPP 

#include "../include/product.hpp"

product::product(std::string _name, float _cost, int _stock){
    name = _name;
    cost = _cost;
    stock = _stock;
}

product::product(std::string _name, float _cost){
    name = _name;
    cost = _cost;
    stock = 0;
}

product::~product(){
    //Nothing to be destroyed
}

void product::changeName(std::string _name){
    name = _name;
}

std::string product::getName(){
    return name;
}

void product::changeCost(float _cost){
    cost = _cost;
}

float product::getCost(){
    return cost;
}

bool product::sellProduct(){
    if (stock>=1){
        stock--;
        return true;
    }
    else{
        std::cout << "Error, can't sell product, stock is 0\n";
        return false;
    }
}

void product::addStock(int add_stock){
    stock += add_stock;
}

#endif //PRODUCT_CPP