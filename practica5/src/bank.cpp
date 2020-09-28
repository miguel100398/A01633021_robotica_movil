#ifndef BANK_CPP
#define BANK_CPP

#include <iostream>
#include <string>
#include <ctime>

typedef struct client_s{
    int Client_ID;
    std::string Client_Name;
    double Account_Amount;
    time_t Date_subscription;
    double debt;
} client_t;

typedef struct client_system_s{
    int size;
    int next_id;
    client_t** clients;
}   client_system_t;

void add_client(client_system_t *client_system);
void show_all_clients(client_system_t *client_system);
void add_ammount_account_client(client_system_t *client_system);
void add_debt_client(client_system_t *client_system);
void delete_client(client_system_t *client_system);
void pay_debt(client_system_t *client_system);

int main(){

    return 0;
}

void add_client(client_system_t *client_system){
    std::string tmp_name;
    client_t** tmp = new (std::nothrow) client_t*[client_system->size+1];       //Allocate new array of pointers
    if (tmp==NULL){
        std::cout << "Error allocating memory for clients array\n";
        return;
    }
    tmp = client_system->clients;
    if (client_system->size>0){
        for (int idx=0; idx<client_system->size; idx++){
            delete(client_system->clients[idx]);            //Delete structs
        }       
        delete[] client_system->clients;                    //Delete array of pointers
    }
    client_system->clients = tmp;
    client_system->clients[client_system->size] = new (std::nothrow) client_t;    //Allocate new struct
    if (client_system->clients[client_system->size]==NULL){
        std::cout << "Error allocating memory for new client \n";
        return;
    }
    client_system->clients[client_system->size]->Client_ID = client_system->next_id++;
    std::cout << "Introduce name: ";
    std::cin >> tmp_name;
    client_system->clients[client_system->size]->Client_Name =tmp_name;
    std::cout << "Introduce Account amount: ";
    std::cin >> client_system->clients[client_system->size]->Account_Amount;
    std::cout << "Introduce Debt: ";
    std::cin >> client_system->clients[client_system->size]->debt;
    client_system->clients[client_system->size]->Date_subscription = std::time(0);  //get actual time;
    client_system->size++;
}

void show_all_clients(client_system_t *client_system){
    std::cout << "| ID \t| Name \t| Amount \t| Debt \t| Date subscription\t|\n";
    for (int idx=0; idx<client_system->size; idx++){
        std::cout <<"| "<<client_system->clients[idx]->Client_ID<<"\t|";
        std::cout <<"| "<<client_system->clients[idx]->Client_Name<<"\t|";
        std::cout <<"| "<<client_system->clients[idx]->Account_Amount<<"\t|";
        std::cout <<"| "<<client_system->clients[idx]->debt<<"\t|";
        std::cout <<"| "<<ctime(&(client_system->clients[idx]->Date_subscription))<<"\t|\n";
    }
}

void add_ammount_account_client(client_system_t *client_system){
    int ID;
    double ammount;
    std::cout << "Introduce Client ID to add ammount: ";
    std::cin >> ID;
    
    for (int idx=0; idx<client_system->size;idx++){
        if (client_system->clients[idx]->Client_ID==ID){
            std::cout << "Introduce Ammount: ";
            std::cin >> ammount;
            client_system->clients[idx]->Account_Amount+=ammount;
            return;
        }
    }
    std::cout << "Error, can´t find client ID: " << ID;
}

void add_debt_client(client_system_t *client_system){
    int ID;
    double debt;
    std::cout << "Introduce Client ID to add debt: ";
    std::cin >> ID;
    
    for (int idx=0; idx<client_system->size;idx++){
        if (client_system->clients[idx]->Client_ID==ID){
            std::cout << "Introduce debt: ";
            std::cin >> debt;
            client_system->clients[idx]->debt+=debt;
            return;
        }
    }
    std::cout << "Error, can´t find client ID: " << ID;
}

void delete_client(client_system_t *client_system){
    client_t** tmp;
    int ID;
    bool found = false;
    std::cout << "Introduce ID to delete client: ";
    std::cin >> ID;
    for (int idx=0; idx<client_system->size;idx++){
        if (client_system->clients[idx]->Client_ID==ID){
            found = true;
            client_system->clients[idx] = client_system->clients[client_system->size-1];    //Move last element 
            delete (client_system->clients[client_system->size-1]);     //Delete last element
            break;
        }
    }
    if (!found){
        std::cout << "Error, can´t find client ID: " << ID;
        return;
    }
    
    tmp = new (std::nothrow) client_t*[client_system->size-1];       //Allocate new array of pointers
    if (tmp==NULL){
        std::cout << "Error allocating memory for clients array\n";
        return;
    }
    tmp = client_system->clients;
    for (int idx=0; idx<client_system->size-1;idx++){
        delete(client_system->clients[idx]);        //delete clients
    }
    delete[] client_system->clients;            //delete array of clients;
    client_system->clients = tmp;       //points to new array

}

void pay_debt(client_system_t *client_system){
    int ID;
    std::cout << "Introduce Client ID to add debt: ";
    std::cin >> ID;
    
    for (int idx=0; idx<client_system->size;idx++){
        if (client_system->clients[idx]->Client_ID==ID){
            if (client_system->clients[idx]->Account_Amount>=client_system->clients[idx]->debt){
                client_system->clients[idx]->Account_Amount -= client_system->clients[idx]->debt;
                client_system->clients[idx]->debt = 0;
                std::cout << "Debt paid\n";
                return;
            }else{
                std::cout << "Error, Cant pay debt, insufficient money\n";
                return;
            }
        }
    }
    std::cout << "Error, can´t find client ID: " << ID;
}

#endif //BANK_CPP