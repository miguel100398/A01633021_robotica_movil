#ifndef HANGMAN_CPP
#define HANGMAN_CPP

#include <iostream>
#include <string>
#include <unistd.h>

#define WORD_ARRAY_SIZE 10

bool is_in_word(char character, std::string word, bool *known_characters);
std::string get_word(const std::string *array_words, unsigned int array_size);
void print_unknown_characters(std::string word, bool *known_characters);
void print_hangman(unsigned int lifes);

const std::string words[WORD_ARRAY_SIZE] = {
    "cat",
    "dog",
    "house",
    "student",
    "proffesor",
    "school",
    "door",
    "robot",
    "miguel",
    "car"
};

int main(){
    std::string selected_word;
    char input_char;
    int lifes = 6;
    int remaining_chars = 0;
    //Select random word
    srand (time(NULL));
    selected_word = get_word(words, WORD_ARRAY_SIZE);
    remaining_chars = selected_word.length();
    bool known_characters[selected_word.length()];
    for (int idx=0; idx<selected_word.length(); idx++){
        known_characters[idx] = false;
    }
    //Print word for first time
    print_unknown_characters(selected_word, known_characters);
    while (lifes > 0){
        std::cout << "Introduce character \n";
        std::cin >> input_char;
        if (is_in_word(input_char, selected_word, known_characters)){
            print_unknown_characters(selected_word, known_characters);
            if (--remaining_chars==0){
                break;
            }
        }else{
            print_unknown_characters(selected_word, known_characters);
            std::cout << "Remaining lifes: " << std::to_string(--lifes) << "\n";
            print_hangman(lifes);
        }
    }

    if (remaining_chars == 0){
        std::cout << "You Win!!!!!! \n";
    }else{
        std::cout << "You Lost, The correct word was: " << selected_word << "\n";
    }
    return 0;
}

bool is_in_word(char character, std::string word, bool *known_characters){
    for (int idx=0; idx<word.length(); idx++){
        if ((word[idx] == character)||((word[idx]-32)== character)){
            if (!known_characters[idx]){
                known_characters[idx] = true;
                return true;
            }
        }
    }
    return false;
}

std::string get_word(const std::string *array_words, unsigned int array_size){
    return array_words[rand()%array_size];
}

void print_unknown_characters(std::string word, bool *known_characters){
    for (int idx=0; idx<word.length(); idx++){
        if (known_characters[idx]){
            std::cout << word[idx];
        }else{
            std::cout << "*";
        }
    }
    std::cout << "\n";
}

void print_hangman(unsigned int lifes){
    if (lifes == 6){
        std::cout << "\n";
        return;
    }
    std::cout << "   ( )   \n";
    if (lifes == 5){
        std::cout << "\n";
        return;
    }
    std::cout << "  / ";
    if (lifes == 4){
        std::cout << "\n";
        return;
    }
    std::cout <<"|";
    if (lifes == 3){
        std::cout << "\n";
        return;
    }
    std::cout << " \\   \n";
    if (lifes == 2){
        std::cout << "\n";
        return;
    }
    std::cout << "   /";
    if (lifes == 1){
        std::cout << "\n";
        return;
    }
    std::cout <<" \\   \n";
    return;
}

#endif //HANGMAN_CPP