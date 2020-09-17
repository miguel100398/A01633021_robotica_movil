#ifndef OCCURRENCE_CPP
#define OCCURRENCE_CPP

#include <iostream>
#include <string>
#include <unistd.h>

int main(){
    std::string input_message;
    std::string output_message = "";
    char character;
    unsigned int occurrences = 0;

    //Introduce message and character
    std::cout << "Introduce message \n";
    std::getline(std::cin, input_message);
    std::cout << "Introduce character \n";
    std::cin >> character;

    for (int idx=0; idx<input_message.length(); idx++){
        if (input_message[idx] == character){
            occurrences++;
        }else{
            output_message += input_message[idx];
        }
    }

    std::cout << "Number of occurrences: " << std::to_string(occurrences) << "\n";
    std::cout << "Modified message \n";
    std::cout << output_message << "\n";
}

#endif // OCCURRENCE_CPP