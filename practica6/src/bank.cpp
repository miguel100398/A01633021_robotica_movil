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
    if (size==0) return; //Nothing to destroy
    while(tmp->getNextNode()!=NULL){
        
    }
}

#endif // BANK_CPP