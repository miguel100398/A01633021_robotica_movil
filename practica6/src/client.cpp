#ifndef CLIENT_CPP  
#define CLIENT_CPP  

#include "../include/client.hpp"

client::client(std::string name){
    srand (time(NULL));
    client_id = rand();
    client_name = name;
    account_amount = 0;
    date_subscription = std::time(0);
    debt = 0;
}

std::string client::getName(){
    return client_name;
}

double client::getAccountAmount(){
    return account_amount;
}

void client::addAccountAmount(double ammount){
    account_amount+=ammount;
}

time_t client::getDateSubscription(){
    return date_subscription;
}

double client::getDebt(){
    return debt;
}

void client::addAccountDebt(double add_debt){
    debt += debt;
}

bool client::payDebt(){
    if (account_amount>=debt){
        account_amount-=debt;
        debt=0;
        return true;
    }else{
        return false;
    }
}

client::~client(){
    //Nothing to be destroyed
}

#endif