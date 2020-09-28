#ifndef BANK_CPP
#define BANK_CPP

#include <bits/types/struct_tm.h>
#include <iostream>
#include <new>
#include <string>
#include <ctime>

typedef struct client_s{
    int Client_ID;
    std::string Client_Name;
    double Account_Amount;
    time_t Date_subscription;
    double debt;
} client_t;

typedef struct node_linkedList_s{
    client_t *client;
    node_linkedList_s *prev_client;
    node_linkedList_s *next_client;
} node_linkedList_t;

typedef struct linkedList_s{
    node_linkedList_t *first_node;
    node_linkedList_t *last_node;
    int size;
    int nextID;
}   linkedList_t;

void add_client(linkedList_t *client_system);
void show_all_clients(linkedList_t *client_system);
void add_amount_account_client(linkedList_t *client_system);
void add_debt_client(linkedList_t *client_system);
void delete_client(linkedList_t *client_system);
void pay_debt(linkedList_t *client_system);
void new_clientSystem(linkedList_t *client_system);
void delete_clientSystem(linkedList_t *client_system);
bool exists_id(linkedList_t *client_sytem, int ID, node_linkedList_t **node);

int main(){
    int operation;
    linkedList_t client_system;
    bool exit = false;
    std::cout << "Creating client system \n";
    new_clientSystem(&client_system);
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
                add_client(&client_system);
                break;
            case 1:
                show_all_clients(&client_system);
                break;
            case 2:
                add_amount_account_client(&client_system);
                break;
            case 3:
                add_debt_client(&client_system);
                break;
            case 4:
                delete_client(&client_system);
                break;
            case 5:
                pay_debt(&client_system);
                break;
            default:
                exit = true;
                break;
        }
    }
    delete_clientSystem(&client_system);
    return 0;
}

void add_client(linkedList_t *client_system){
    std::string tmp_name;
    node_linkedList_t* tmp_node;
    client_t* tmp_client;
    tmp_node = client_system->first_node;
    if (client_system->size==0){
        client_system->first_node = new (std::nothrow) node_linkedList_t;
        if (client_system->first_node==NULL){
            std::cout << "Error allocating memory for node\n";
            return;
        }
        client_system->first_node->prev_client = NULL;
        client_system->first_node->next_client = NULL; 
        tmp_node = client_system->first_node;
    }else{
        while(tmp_node->next_client!=NULL){
            tmp_node = tmp_node->next_client;
        }
        tmp_node->next_client = new (std::nothrow) node_linkedList_t;
        if (tmp_node->next_client==NULL){
            std::cout << "Error allocating memory for node\n";
            return;
        }
        tmp_node->next_client->next_client=NULL;
        tmp_node->next_client->prev_client=tmp_node;
        tmp_node = tmp_node->next_client;
    }
    tmp_node->client = new (std::nothrow) client_t;
    if (tmp_node->client==NULL){
        std::cout << "Error allocating memory for client \n";
        return;
    }
    tmp_client = tmp_node->client;
    tmp_client->Client_ID = client_system->nextID++;
    std::cout << "Introduce name: ";
    std::cin >> tmp_name;
    tmp_client->Client_Name =tmp_name;
    std::cout << "Introduce Account amount: ";
    std::cin >> tmp_client->Account_Amount;
    std::cout << "Introduce Debt: ";
    std::cin >> tmp_client->debt;
    tmp_client->Date_subscription = std::time(0);  //get actual time;
    client_system->last_node = tmp_node;
    client_system->size++;
}

void show_all_clients(linkedList_t *client_system){
    node_linkedList_t* tmp_node;
    client_t* tmp_client;
    std::cout << "| ID \t|   Name   \t| Amount \t| Debt \t| Date subscription\t|\n";
    if (client_system->size==0){
        return;
    }
    tmp_node = client_system->first_node;
    for (int idx=0; idx<client_system->size-1;idx++){
        tmp_client = tmp_node->client;
        std::cout <<"| "<<tmp_client->Client_ID<<"\t|";
        std::cout <<" "<<tmp_client->Client_Name<<"\t|";
        std::cout <<" "<<tmp_client->Account_Amount<<"\t\t|";
        std::cout <<" "<<tmp_client->debt<<"\t|";
        std::cout <<" "<<ctime(&(tmp_client->Date_subscription));
        tmp_node = tmp_node->next_client;
    }
    tmp_client = tmp_node->client;
    std::cout <<"| "<<tmp_client->Client_ID<<"\t|";
    std::cout <<" "<<tmp_client->Client_Name<<"\t|";
    std::cout <<" "<<tmp_client->Account_Amount<<"\t\t|";
    std::cout <<" "<<tmp_client->debt<<"\t|";
    std::cout <<" "<<ctime(&(tmp_client->Date_subscription));
}

void add_amount_account_client(linkedList_t *client_system){
    int ID;
    double amount;
    node_linkedList_t* tmp_node;
    std::cout << "Introduce ID to add amount: ";
    std::cin >> ID;
    if(!exists_id(client_system, ID, &tmp_node)){
        std::cout << "Error Client with ID not found: " << ID << "\n";
        return;
    }
    std::cout << "Introduce amount to be added: ";
    std::cin >> amount;
    tmp_node->client->Account_Amount+=amount;
}

void add_debt_client(linkedList_t *client_system){
    int ID;
    double debt;
    node_linkedList_t* tmp_node;
    std::cout << "Introduce ID to add debt: ";
    std::cin >> ID;
    if(!exists_id(client_system, ID, &tmp_node)){
        std::cout << "Error Client with ID not found: " << ID << "\n";
        return;
    }
    std::cout << "Introduce debt to be added: ";
    std::cin >> debt;
    tmp_node->client->debt+=debt;
}

void delete_client(linkedList_t *client_system){
    int ID;
    node_linkedList_t* tmp_node;
    std::cout << "Introduce Client ID to delete: ";
    std::cin >> ID;
    if (!exists_id(client_system, ID, &tmp_node)){
        std::cout << "Error Client with ID not found: " << ID << "\n";
        return;
    }
    if (tmp_node==client_system->first_node){           //Deleting first node
        if (client_system->size<=1){
            delete(tmp_node->client);
            delete(tmp_node);
        }else{
            client_system->first_node = tmp_node->next_client;
            client_system->first_node->prev_client = NULL;
            delete(tmp_node->client);
            delete(tmp_node);
        }
    }else if(tmp_node==client_system->last_node){       //Deleting last node
        if (client_system->size<=1){
            delete(tmp_node->client);
            delete(tmp_node);
        }else{
            client_system->last_node = tmp_node->prev_client;
            client_system->last_node->next_client = NULL;
            delete(tmp_node->client);
            delete(tmp_node);
        }
    }
    else{                                //Deleting Intermediate node
        delete(tmp_node->client);       //Free client memory
        tmp_node->prev_client->next_client = tmp_node->next_client; //Delete pointer from linked list
        tmp_node->next_client->prev_client = tmp_node->prev_client;
        delete(tmp_node);       //Free node memory
    }
    client_system->size--;
}

void pay_debt(linkedList_t *client_system){
    int ID;
    node_linkedList_t *tmp_node;
    client_t *tmp_client;
    std::cout << "Introduce Client ID to add debt: ";
    std::cin >> ID;

    if (!exists_id(client_system, ID, &tmp_node)){
        std::cout << "Error client with ID doesn´t exist: " << ID << "\n";
        return;
    }
    tmp_client = tmp_node->client;
    if (tmp_client->Account_Amount>=tmp_client->debt){
        tmp_client->Account_Amount-=tmp_client->debt;
        tmp_client->debt=0;
        std::cout << "Debt paid\n";
    }else{
        std::cout << "Error, Cant pay debt, insufficient money\n";
    }
    
}

void new_clientSystem(linkedList_t *client_system){
    client_system->nextID=0;
    client_system->size=0;
    client_system->first_node=NULL;
    client_system->last_node=NULL;
}

void delete_clientSystem(linkedList_t *client_system){
    node_linkedList_t* tmp_node;
    if (client_system->size==0){
        std::cout << "Client System deleted \n";
        return;
    }
    tmp_node = client_system->first_node;
    for (int idx=0; idx<client_system->size-1;idx++){
        tmp_node = tmp_node->next_client;
        delete(tmp_node->prev_client->client);
        delete(tmp_node->prev_client);
    }
    delete(tmp_node->client);
    delete(tmp_node);
    client_system->size = 0;
    std::cout << "Client System deleted \n";
}

bool exists_id(linkedList_t *client_sytem, int ID, node_linkedList_t **node){
    node_linkedList_t* tmp_node;
    if (client_sytem->size==0){
        return false;
    }
    tmp_node = client_sytem->first_node;
    for (int idx=0; idx<client_sytem->size-1;idx++){
        if (tmp_node->client->Client_ID==ID){
            *node =tmp_node;
            return true;
        }else{
            tmp_node = tmp_node->next_client;
        }
    }
    if (tmp_node->client->Client_ID==ID){
        *node =tmp_node;
        return true;
    }
    return false;
}


#endif //BANK_CPP