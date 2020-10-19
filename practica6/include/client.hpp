#ifndef CLIENT_HPP  
#define CLIENT_HPP  

#include <string>
#include <ctime>

class client{
    private:
        int client_id;
        std::string client_name;
        double account_amount;
        time_t date_subscription;
        double debt;
    public:
        client(std::string name);
        ~client();
        std::string getName();
        double getAccountAmount();
        void addAccountAmount(double ammount);
        time_t getDateSubscription();
        double getDebt();
        void addAccountDebt(double add_debt);
        bool payDebt();

};

#endif //CLIENT_HPP