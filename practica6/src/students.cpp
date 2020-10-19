#ifndef STUDENTS_CPP 
#define STUDENTS_CPP 

#include "../include/students.hpp"

students::students(){
    //Do nothing in default contructor
}

students::students(std::string name, float partial1, float partial2, float final){
    student_name = name;
    score_partial1 = partial1;
    score_partial2 = partial2;
    score_final = final;
    faults = 0;
}

students::~students(){
    //Nothing to be destroyed
}

std::string students::getName(){
    return student_name;
}

float students::getScorePartial1(){
    return score_partial1;
}

float students::getScorePartial2(){
    return score_partial2;
}

float students::getScoreFinal(){
    return score_final;
}

int students::getFaults(){
    return faults;
}

void students::addFaults(int add_faults){
    faults += add_faults;
}

#endif //STUDENTS_CPP