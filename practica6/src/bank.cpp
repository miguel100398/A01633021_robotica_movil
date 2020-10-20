#ifndef BANK_CPP  
#define BANK_CPP  

#include "../include/bank.hpp"

bank::bank(){
    first_node = NULL;
    last_node = NULL;
    size = 0;
}

bank::~bank(){
    //Delete all nodes
    node_linkedList<client>* tmp;
    node_linkedList<client>* del_tmp;
    if (size==0) return; //Nothing to destroy
    tmp = first_node;
    while (tmp->getNextNode()!=NULL){
        del_tmp = tmp;
        tmp = tmp->getNextNode();
        delete del_tmp;
    }
    delete tmp;
}

bool bank::exists_id(int ID, node_linkedList<client>** node){
    node_linkedList<client>* tmp;
    if (size==0){
        return false;
    }
    tmp = first_node;
    for (int idx=0; idx<size; idx++){
        if (tmp->getData()->getID()==ID){
            *node = tmp;
            return true;
        }
        tmp = tmp->getNextNode();
    }
    return false;
}

bool bank::exists_name(std::string name, node_linkedList<client>** node){
    node_linkedList<client>* tmp;
    if (size==0){
        return false;
    }
    tmp = first_node;
    for (int idx=0; idx<size; idx++){
        if (tmp->getData()->getName()==name){
            *node = tmp;
            return true;
        }
        tmp = tmp->getNextNode();
    }
    //Node not found
    return false;
}

void bank::addClient(){
    node_linkedList<client>* tmp;
    std::string name;
    std::cout << "Introduce name: ";
    std::cin >> name;
    tmp = new node_linkedList<client>(new client(name),NULL,NULL);
    if (size==0){
        first_node = tmp;
        last_node = first_node;
    } else {
        last_node->setNextNode(tmp);
        tmp->setPrevNode(last_node);
        last_node = tmp;

    }
    size++;
}

void bank::showAllClients(){
    client* tmp_client;
    node_linkedList<client>* tmp_node;
    std::cout << "| ID \t|   Name   \t| Amount \t| Debt \t| Date subscription\t|\n";
    if (size==0){
        return;
    }
    tmp_node = first_node;
    for (int idx=0; idx<size; idx++){
        tmp_client = tmp_node->getData();
        std::cout <<"| "<<tmp_client->getID()<<"\t|";
        std::cout <<" "<<tmp_client->getName()<<"\t|";
        std::cout <<" "<<tmp_client->getAccountAmount()<<"\t\t|";
        std::cout <<" "<<tmp_client->getDebt()<<"\t|";
        std::cout <<" "<<ctime((tmp_client->getDateSubscription()));
        tmp_node = tmp_node->getNextNode();
    }
}

void bank::addAmmountClientAccount(){
    int ID;
    double amount;
    node_linkedList<client>* tmp_node;
    std::cout << "Introduce ID to add amount: ";
    std::cin >> ID;
    if(!exists_id(ID, &tmp_node)){
        std::cout << "Error Client with ID not found: " << ID << "\n";
        return;
    }
    std::cout << "Introduce amount to be added: ";
    std::cin >> amount;
    tmp_node->getData()->addAccountAmount(amount);
}

void bank::addDebtClient(){
    int ID;
    double debt;
    node_linkedList<client>* tmp_node;
    std::cout << "Introduce ID to add debt: ";
    std::cin >> ID;
    if(!exists_id(ID, &tmp_node)){
        std::cout << "Error Client with ID not found: " << ID << "\n";
        return;
    }
    std::cout << "Introduce debt to be added: ";
    std::cin >> debt;
    tmp_node->getData()->addAccountDebt(debt);
}

bool bank::deleteClient(){
    std::string name;
    node_linkedList<client>* tmp_node;
    std::cout << "Introduce Client name to delete: ";
    std::cin >> name;
    if (!exists_name(name, &tmp_node)){
        std::cout << "Error can't delete client, client not found \n";
        return false;
    }
    if (size==1){
        first_node=NULL;
        last_node=NULL;
    }
    else if (tmp_node==first_node){  //Deleting first node
        first_node = tmp_node->getNextNode();
        first_node->setPrevNode(NULL);
    }
    else if (tmp_node==last_node){ //Deleting last node
        last_node = tmp_node->getPrevNode();
        last_node->setNextNode(NULL);
    }else{                          //Delete intermediate node
        tmp_node->getPrevNode()->setNextNode(tmp_node->getNextNode());
    }
    delete tmp_node;
    size--;
    std::cout << "Node deleted succesfully\n";
    return true;
}

bool bank::payDebt(){
    int ID;
    node_linkedList<client>* tmp_node;
    std::cout << "Introduce Client ID to add debt: ";
    std::cin >> ID;

    if (!exists_id(ID, &tmp_node)){
        std::cout << "Error client with ID doesn´t exist: " << ID << "\n";
        return false;
    }

    if (!tmp_node->getData()->payDebt()){
        std::cout << "Error, can't pay debt, not enough money \n";
        return false;
    }
    std::cout << "Debt paid succesfuly \n";
    return true;
}

#endif // BANK_CPP