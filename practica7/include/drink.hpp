#ifndef DRINK_HPP  
#define DRINK_HPP  

#include "product.hpp"

class drink : public product{
    protected:
        float liters;
        time_t dateExpiry;
        float density;
    public:
        drink(std::string _name, float _cost, int _stock, float _liters, time_t _expiry, float _density);
        ~drink();
        virtual void setLiters(float _liters);
        virtual float getLitters();
        virtual void addDateExpiry(time_t _date);
        virtual time_t* getDateExpiry();
        virtual void addDensity(float _density);
        virtual float getDensity();
        virtual float getCost();
};

#endif //DRINK_HPP