#ifndef MARKET_CPP  
#define MARKET_CPP  

#include "../include/market.hpp"
#include <ctime>
#include <string>

market::~market(){
    std::map<std::string,product*>::iterator iterator;
    iterator = vegetableMap.begin();
    while (iterator!=vegetableMap.end()){
        delete iterator->second;
        iterator++;
    }
    iterator = drinkMap.begin();
    while (iterator!=drinkMap.end()){
        delete iterator->second;
        iterator++;
    }
}

void market::addProductStock(){
    std::map<std::string,product*>::iterator iterator;
    std::map<std::string,product*> tmp_map;
    std::string type;
    std::string name;
    int add_stock;
    bool found = false;
    std::cout << "Introduce type of product(vegetable, drink): ";
    std::cin >> type;

    if (type=="vegetable"){
        tmp_map = vegetableMap;
    } else if (type=="drink"){
        tmp_map = drinkMap;
    }else{
        std::cout << "Error can't add product, type is not valid, valid are vegetable and drink\n";
        return;
    }


    std::cout << "Introduce name of product: ";
    std::cin >> name;

    iterator = tmp_map.begin();
    //Iterate over map
    while (iterator != tmp_map.end()){
        if (iterator->first==name){
            //Element found
            found = true;
            break;
        }
        iterator++;
    }

    if (found){
        std::cout << "Product found \n";
        std::cout << "introduce stock to be added: ";
        std::cin >> add_stock;
        iterator->second->addStock(add_stock);
    }else{
        std::cout << "Product not found, register new product\n";
        if (type=="vegetable"){
            float weight;
            float price_weight;
            std::cout << "introduce weight: ";
            std::cin >> weight;
            std::cout << "introduce price weight: ";
            std::cin >> price_weight;
            vegetable* tmp_veg = new vegetable(name,weight,price_weight,add_stock);
            vegetableMap.insert(std::pair<std::string,product*>(name,tmp_veg));
        }else if (type=="drink"){
            struct tm* time;
            time_t expiration;
            float cost;
            float liters;
            float density;
            int e_days;
            int e_month;
            int e_year;
            std::cout << "Introduce cost: ";
            std::cin >> cost;
            std::cout << "Introduce liters: ";
            std::cin >> liters;
            std::cout << "Introduce density: ";
            std::cin >> density;
            std::cout << "Introduce expiration date(day): ";
            std::cin >> e_days;
            std::cout << "Introduce expiration date(month): ";
            std::cin >> e_month;
            std::cout << "Introduce expiration date(year): ";
            std::cin >> e_year;

            time->tm_year = 1900-e_year;
            time->tm_mon = e_month;
            time->tm_mday = e_days;
            expiration = mktime(time);
            drink* tmp_drink = new drink(name, cost, add_stock, liters, expiration, density);
            drinkMap.insert(std::pair<std::string,product*>(name,tmp_drink));

        }else{
            std::cout << "Error can't add product, type is not valid, valid are vegetable and drink\n";
            return;
        }
    }
}

void market::showAllProducts(){

}

void market::showTypeofProduct(){

}

void market::deleteProduct(){

}

void market::shopping(){
    
}



#endif //MARKET_CPP