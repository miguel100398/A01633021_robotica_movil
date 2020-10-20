#ifndef MARKET_CPP  
#define MARKET_CPP  

#include "../include/market.hpp"
#include <ctime>
#include <iostream>
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
    std::map<std::string,product*>::iterator iterator;
    std::string type;

    std::cout << "|product type||Name\t|| Cost \t|| Stock \t|\n";
    //Show vegetables
    type = "vegetables";
    iterator = vegetableMap.begin();
    while (iterator != vegetableMap.end()){
        vegetable* tmp;
        tmp = (vegetable*)iterator->second;
        std::cout << "| vegetable |";
        std::cout << "|" <<tmp->getName()<<"\t|";
        std::cout << "|" <<tmp->getPriceWeight()<<"\t|";
        std::cout << "|" <<tmp->getStock()<<"\t|\n";
        iterator++;
    }
    //show drinks
    type = "drinks";
    iterator = drinkMap.begin();
    while(iterator != drinkMap.end()){
        drink* tmp;
        tmp = (drink*)iterator->second;
        std::cout << "|   drinks  |";
        std::cout << "|" <<tmp->getName()<<"\t|";
        std::cout << "|" <<tmp->getCost()<<"\t|";
        std::cout << "|" <<tmp->getStock()<<"\t|\n";
        iterator++;
    }
}

void market::showTypeofProduct(){
    std::map<std::string,product*>::iterator iterator;
    std::string type;

    std::cout << "Introduce type(vegetable, drink): ";
    std::cin >> type;

    if (type == "vegetable"){
        std::cout << "|Name\t|| Cost \t|| Stock \t|| weight \t|| date \t|\n";
        iterator = vegetableMap.begin();
        while (iterator != vegetableMap.end()){
            vegetable* tmp =(vegetable*) iterator->second;
            std::cout << "|" <<tmp->getName()<<"\t|";
            std::cout << "|" <<tmp->getPriceWeight()<<"\t|";
            std::cout << "|" <<tmp->getStock()<<"\t|";
            std::cout << "|" <<tmp->getWeight()<<"\t|";
            std::cout << "|" <<ctime(tmp->getDate())<<"\t|\n";
            iterator++;
        }
    }else if (type == "drink"){
        std::cout << "|Name\t|| Cost \t|| Stock \t|| liters \t|| exp date \t|| density \t|\n";
        iterator = drinkMap.begin();
        while (iterator != drinkMap.end()){
            drink* tmp =(drink*) iterator->second;
            std::cout << "|" <<tmp->getName()<<"\t|";
            std::cout << "|" <<tmp->getCost()<<"\t|";
            std::cout << "|" <<tmp->getStock()<<"\t|";
            std::cout << "|" <<tmp->getLitters()<<"\t|";
            std::cout << "|" <<ctime(tmp->getDateExpiry())<<"\t|";
            std::cout << "|" <<tmp->getDensity()<<"\t|\n";
            iterator++;
        }
    }else {
        std::cout << "Error, wronk type\n";
    }
}

void market::deleteProduct(){
    std::map<std::string,product*>::iterator iterator;
    std::string type;
    std::string name;

    std::cout << "Introduce type to delete(vegetable, drink): ";
    std::cin >> type;

    std::cout << "Introduce name of product: ";
    std::cin >> name;

    if (type == "vegetable"){
        iterator = vegetableMap.find(name);
        if (iterator== vegetableMap.end()){
            std::cout << "Error, product not found";
            return;
        }
        delete iterator->second;
        vegetableMap.erase(iterator);
    }else if (type == "drink"){
        iterator = drinkMap.find(name);
        if (iterator== drinkMap.end()){
            std::cout << "Error, product not found";
            return;
        }
        delete iterator->second;
        drinkMap.erase(iterator);
    }else {
        std::cout << "Error, Can't delete item, incorrect type\n";
    }
}

void market::shopping(){
    std::map<std::string,product*>::iterator iterator;
    float total=0;
    std::vector<std::string> products;
    std::string product;
    
    while (true){
        std::cout << "Introduce product to buy or write \"buy\" to buy the products: ";
        std::cin >> product;
        if (product=="buy"){
            break;
        }else{
            iterator = vegetableMap.find(product);
            if (iterator != vegetableMap.end()){
                vegetable* tmp =(vegetable*) iterator->second;
                if (tmp->sellProduct()){
                    total += tmp->getCost(tmp->getWeight());
                    products.push_back(product);
                }
            }else{
                iterator = drinkMap.find(product);
                if (iterator != drinkMap.end()){
                    drink* tmp =(drink*) iterator->second;
                    if (tmp->sellProduct()){
                        total += tmp->getCost();
                        products.push_back(product);
                    }
                }else{
                    std::cout << "Error, product not found\n";
                }
            }

        }
    }

    std::cout << "Total: " << total <<"\n";
    std::cout << "products: ";
    while (products.size()>0){
        std::cout << products.back() << ", ";
        products.pop_back();
    }
    std::cout << "\n";
}



#endif //MARKET_CPP