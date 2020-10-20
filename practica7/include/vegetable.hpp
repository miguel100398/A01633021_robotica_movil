#ifndef VEGETABLE_HPP
#define VEGETABLE_HPP 

#include "product.hpp"

class vegetable : public product{
    protected:
        float weight;
        time_t date;
        float price_due_weight;
    public:
        vegetable(std::string _name, float _weight, float _priceweight, int _stock);
        ~vegetable();
        virtual void setWeight(float _weight);
        virtual float getWeight();
        virtual time_t* getDate();
        virtual void updateDate();
        virtual void changePriceWeight(float _price);
        virtual float getPriceWeight();
        virtual float getCost(float _sellWeight);
        virtual void changeName(std::string _name);
        virtual void changeCost(float _cost);
        virtual bool sellProduct();
        virtual void addStock(int add_stock);

};

#endif // VEGETABLE_HPP
