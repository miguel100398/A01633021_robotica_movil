#ifndef PRODUCT_HPP  
#define PRODUCT_HPP 

#include <string>
#include <iostream>

class product{
    protected:
        std::string name;
        float cost;
        int stock;
    public:
        product(std::string _name, float _cost, int _stock);
        product(std::string _name, float _cost);
        ~product();
        virtual void changeName(std::string _name);
        virtual std::string getName();
        virtual void changeCost(float _cost);
        virtual float getCost();
        virtual bool sellProduct();
        virtual void addStock(int add_stock);
        virtual int getStock();
};

#endif //PRODUCT_HPP