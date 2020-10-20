#ifndef MARKET_HPP  
#define MARKET_HPP  

#include "product.hpp"
#include "vegetable.hpp"
#include "drink.hpp"
#include <map>
#include <vector>

//mymap.insert ( std::pair<char,int>('a',100) );
// mymap.find('a')->second

class market{
    protected:
        std::map<std::string, product*> vegetableMap;      //associative array to store vegetables
        std::map<std::string, product*>     drinkMap;          //associative array to store drinks
    public:
        ~market();
        void addProductStock();
        void showAllProducts();
        void showTypeofProduct();
        void deleteProduct();
        void shopping();

};

#endif // MARKET_HPP