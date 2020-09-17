#ifndef COUNTER_CPP
#define COUNTER_CPP

#include <iostream>
#include <string>
#include <unistd.h>

int main(){
    std::string Message;
    char character;
    unsigned int alphabet_cnt = 0;  //[65,90],[97-122]
    unsigned int digit_count = 0;   //[48-57]
    unsigned int special_count = 0;

    //Get message;
    std::cout << "Introduza mensaje\n";
    std::getline(std::cin, Message);
    for (int idx=0; idx<Message.length(); idx++){
        character = Message[idx];
        if ((character>=65&&character<=90)||(character>=97&&character<=122)){   //alphabet
            alphabet_cnt++;
        }else if(character>=48&&character<=57){     //digit
            digit_count++;
        }else{      //special
            special_count++;
        }
    }

    //Print results
    std::cout << "Alphabet Count: " << std::to_string(alphabet_cnt) << "\n";
    std::cout << "Digit Count: " << std::to_string(digit_count) << "\n";
    std::cout << "Special Count: " << std::to_string(special_count) << "\n";
    std::cout << "Total Count: " << std::to_string(alphabet_cnt+digit_count+special_count) << "\n";
    return 1;   
}

#endif //COUNTER_CPP