#ifndef BANK_HPP  
#define BANK_HPP  

#include <iostream>
#include "client.hpp"
#include "node_linkedList.hpp"

class bank{
    private:
        node_linkedList<client>* first_node;
        node_linkedList<client>* last_node;
        int size;
        bool exists_id(int ID, node_linkedList<client>** node);
        bool exists_name(std::string name, node_linkedList<client>** node);
    public:
        bank();
        ~bank();
        void addClient();
        void showAllClients();
        void addAmmountClientAccount();
        void addDebtClient();
        bool deleteClient();
        bool payDebt();     
};

#endif //BANK_HPP