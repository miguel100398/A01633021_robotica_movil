#ifndef STUDENTS_MAIN_CPP  
#define STUDENTS_MAIN_CPP  

#include "../include/group.hpp"

int main(){
    //Create group
    int operation;
    bool exit = false;
    group* grp = new group(); 
    while (!exit){
        std::cout << "Introduce operation to be performed \n";
        std::cout << "Add Student -> 0\n";
        std::cout << "Show all students -> 1\n";
        std::cout << "Show unsuccesful students -> 2\n";
        std::cout << "show succesful students -> 3\n";
        std::cout << "Delete student -> 4\n";
        std::cout << "Show student with more faults -> 5\n";
        std::cout << "Add faults to student -> 6\n";
        std::cout << "Exit -> another\n";
        std::cin >> operation;
        switch(operation){
            case 0:
                grp->addStudent();
                break;
            case 1:
                grp->showAllStudents();
                break;
            case 2:
                grp->showUnsuccesfulStudents();
                break;
            case 3:
                grp->showSuccesfulStudents();
                break;
            case 4:
                grp->deleteStudent();
                break;
            case 5:
                grp->showStudentWithMoreFaults();
                break;
            case 6:
                grp->AddStudentFault();
                break;
            default:
                exit = true;
                break;
        }
    }
    //Destroy group
    delete grp;
    return 0;
}

#endif // STUDENTS_MAIN_CPP