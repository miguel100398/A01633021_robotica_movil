#ifndef MAIN_BANK_CPP
#define MAIN_BANK_CPP  

#include "../include/bank.hpp"

int main(){
    bank* banco = new bank();
    int operation;
    bool exit = false;
    while (!exit){
        std::cout << "Introduce Operation to be performed\n";
        std::cout << "Add Client -> 0\n";
        std::cout << "Show all clients -> 1\n";
        std::cout << "Add Amount to client -> 2\n";
        std::cout << "Add debt to client -> 3\n";
        std::cout << "Delete client -> 4\n";
        std::cout << "Pay debt -> 5\n";
        std::cout << "Exit -> other\n";
        std::cin >> operation;
        switch(operation){
            case 0:
                banco->addClient();
                break;
            case 1:
                banco->showAllClients();
                break;
            case 2:
                banco->addAmmountClientAccount();
                break;
            case 3:
                banco->addDebtClient();
                break;
            case 4:
                banco->deleteClient();
                break;
            case 5:
                banco->payDebt();
                break;
            default:
                exit = true;
                break;
        }
    }

    delete banco;
    return 0;
}

#endif //MAIN_BANK_CPP