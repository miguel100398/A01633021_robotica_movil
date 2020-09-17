#ifndef WORDS_CPP
#define WORDS_CPP

#include <iostream>
#include <string>
#include <unistd.h>

int main(){
    std::string message;
    bool f_space = true;
    int words_counter = 0;

    //Introduce message
    std::cout << "Introduce message \n";
    std::getline(std::cin, message);

    for (int idx=0; idx<message.length(); idx++){
        if ((message[idx] == ' ')||(message[idx] == '\n')){
            if (!f_space){
                words_counter++;
            }
            f_space = true;
        }else{
            f_space = false;
        }
    }

    if (!f_space){
        words_counter++;    //Last word
    }

    std::cout << "Number of words: " << std::to_string(words_counter) << "\n";
}

#endif //WORDS_CPP