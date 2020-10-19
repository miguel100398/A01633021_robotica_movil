#ifndef GROUP_CPP
#define GROUP_CPP

#include "../include/group.hpp"

group::group(){
    actual_students=0;
    //Initialize all students to 0
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        stud[idx] = NULL;
    }
}

group::~group(){
    //Destroy all students
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx] != NULL){
            delete stud[idx];
        }
    }
}

bool group::addStudent(){
    std::string name;
    float partial1;
    float partial2;
    float final;
    bool searchFreeSpace = false;
    if (actual_students>=10){
        std::cout << "Cant add more students, the group is full, Max Size is :" << MAX_STUDENTS <<"\n";
        return false;
    }
    //Get student data
    std::cout << "Student name: ";
    std::cin >> name;
    std::cout << "Score Partial 1: ";
    std::cin >> partial1;
    std::cout << "Score Partial 2: ";
    std::cin >> partial2;
    std::cout << "Score final: ";
    std::cin >> final;
    //Search for free space to add students
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!=NULL){
            searchFreeSpace=true;
            //create new student
            stud[idx] = new students(name, partial1, partial2, final);
            break;
        }
    }
    if (!searchFreeSpace){
        std::cout << "Error in searching free space to allocate student, actual size is: " << actual_students << " Max size is: " << MAX_STUDENTS << "\n";
        return false;
    }
    std::cout << "Student created succesfully\n";
    actual_students++;
    return true;
}

void group::showAllStudents(){
    students* tmp;
    std::cout << "|  Name  \t|P1 Score\t|P2 Score\t|Final Score\t|Faults\t|\n";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!=NULL){
            tmp = stud[idx];
            std::cout <<"| " << tmp->getName() << "\t|";
            std::cout <<"     "<< tmp->getScorePartial1() <<"\t\t|";
            std::cout <<"     "<< tmp->getScorePartial1() <<"\t\t|";
            std::cout <<"     "<< tmp->getScoreFinal() <<"\t\t|";
            std::cout <<"   "<< tmp->getFaults() <<"\t|\n";
        }
    }
}

void group::showUnsuccesfulStudents(){
    students* tmp;
    std::cout << "Showing Unsccesful students \n";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!=NULL){
            tmp = stud[idx];
            if (tmp->getScoreFinal() < 7.0){
                std::cout << tmp->getName() << ": " << tmp->getScoreFinal() << "\n";
            }
        }
    }
}

void group::showSuccesfulStudents(){
    students* tmp;
    std::cout << "Showing Unsccesful students \n";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!=NULL){
            tmp = stud[idx];
            if (tmp->getScoreFinal() >= 7.0){
                std::cout << tmp->getName() << ": " << tmp->getScoreFinal() << "\n";
            }
        }
    }
}

bool group::deleteStudent(){
    std::string delete_student;
    if (actual_students<=0){
        std::cout << "Can't delete students, the group is empty\n";
        return false;
    }
    std::cout << "Name of student to be deleted: ";
    std::cin >> delete_student;
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!=NULL){
            if (stud[idx]->getName()==delete_student){
                delete stud[idx];
                stud[idx] = NULL;
                std::cout << "Student deleted succesfully\n";
                actual_students--;
                return true;
            }
        }
    }
    std::cout << "Error, Can´t delete student, Student not found \n";
    return false;
}

void group::showStudentWithMoreFaults(){
    int more_faults=0;
    int idx_moreFaults=-1;
    if (actual_students<=0){
        std::cout << "Can't show student with more faults, group is empty \n";
        return;
    }
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!=NULL){
            if (stud[idx]->getFaults() > more_faults){
                more_faults = stud[idx]->getFaults();
                idx_moreFaults = idx;
            }
        }
    }
    if (idx_moreFaults>=0){
        std::cout << "Student with more faults: " << stud[idx_moreFaults]->getName() << " " << more_faults << "\n";
    }else{
        std::cout << "Error, can't find student with more faults to show \n";
    }
}

bool group::AddStudentFault(){
    int faults;
    std::string name;
    if (actual_students<=0){
        std::cout << "Can't add faults, group is empty \n";
        return false;
    }

    std::cout << "Name of student to add faults: ";
    std::cin >> name;
    std::cout << "Faults to be added: ";
    std::cin >> faults;

    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (stud[idx]!= NULL){
            if (stud[idx]->getName()==name){
                stud[idx]->addFaults(faults);
                std::cout << "Faults added succesfully \n";
                return true;
            }
        }
    }

    std::cout << "Can't add faults, Student not found \n";
    return false;
}

#endif //GROUP_CPP