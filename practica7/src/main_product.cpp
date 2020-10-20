#ifndef MAIN_PRODUCT_CPP  
#define MAIN_PRODUCT_CPP  

#include "../include/vegetable.hpp"
#include "../include/drink.hpp"
#include "../include/market.hpp"

int main(){
    market* mrkt = new market();
    int operation;
    bool exit = false;
    while (!exit){
        std::cout << "Introduce Operation to be performed\n";
        std::cout << "Add product to stock -> 0\n";
        std::cout << "Show all products -> 1\n";
        std::cout << "show type of product -> 2\n";
        std::cout << "delete product -> 3\n";
        std::cout << "shopping -> 4\n";
        std::cout << "Exit -> other\n";
        std::cin >> operation;
        switch(operation){
            case 0:
                mrkt->addProductStock();
                break;
            case 1:
                mrkt->showAllProducts();
                break;
            case 2:
                mrkt->showTypeofProduct();
                break;
            case 3:
                mrkt->deleteProduct();
                break;
            case 4:
                mrkt->shopping();
                break;
            default:
                exit = true;
                break;
        }
    }

    delete mrkt;
    return 0;
}

#endif //MAIN_PRODUCT_CPP