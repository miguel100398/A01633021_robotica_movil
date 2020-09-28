#ifndef STUDENTS_CPP
#define STUDENTS_CPP

#include <iostream>
#include <string>

#define MAX_STUDENTS 10

typedef struct student_s{
    std::string name;
    double score_partial1;
    double score_partial2;
    double score_final;
    int faults;
} student_t;

void init_students(student_t *students[]);
void add_student(student_t *students[]);
void show_all_students(student_t *students[]);
void show_unsuccesful_students(student_t *students[]);
void show_succesful_students(student_t *students[]);
void delete_student(student_t *students[]);
void show_student_more_faults(student_t *students[]);
void delete_all_students(student_t *students[]);

int main(){
    student_t *students[MAX_STUDENTS];
    int operation;
    bool exit = false;
    init_students(students);
    while (!exit){
        std::cout << "Introduce operation to be performed \n";
        std::cout << "Add Student -> 0\n";
        std::cout << "Show all students -> 1\n";
        std::cout << "Show unsuccesful students -> 2\n";
        std::cout << "show succesful students -> 3\n";
        std::cout << "Delete student -> 4\n";
        std::cout << "Show student with more faults -> 5\n";
        std::cout << "Exit -> another\n";
        std::cin >> operation;
        switch(operation){
            case 0:
                add_student(students);
                break;
            case 1:
                show_all_students(students);
                break;
            case 2:
                show_unsuccesful_students(students);
                break;
            case 3:
                show_succesful_students(students);
                break;
            case 4:
                delete_student(students);
                break;
            case 5:
               show_student_more_faults(students);
                break;
            default:
                exit = true;
                break;
        }
    }
    delete_all_students(students);
    return 0;
}

void init_students(student_t *students[]){
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        students[idx] = NULL;
    }
}

void add_student(student_t *students[]){
    std::string tmp_name;
    char tmp[3] = "tm";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]==NULL){
            students[idx] = new student_t;
            std::cout << "Student name: ";
            std::cin >> tmp_name;
            students[idx]->name = tmp_name;
            std::cout << "Score Partial 1: ";
            std::cin >> students[idx]->score_partial1;
            std::cout << "Score Partial 2: ";
            std::cin >> students[idx]->score_partial2;
            std::cout << "Score final: ";
            std::cin >> students[idx]->score_final;
            std::cout << "Faults: ";
            std::cin >>students[idx]->faults;
            return;
        }
    }
    std::cout << "Error, system is full, can´t add more students\n";
}

void show_all_students(student_t *students[]){
    std::cout << "|  Name  \t|P1 Score\t|P2 Score\t|Final Score\t|Faults\t|\n";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]!=NULL){
            std::cout <<"| "<<students[idx]->name<<"\t|";
            std::cout <<"     "<<students[idx]->score_partial1<<"\t\t|";
            std::cout <<"     "<<students[idx]->score_partial2<<"\t\t|";
            std::cout <<"     "<<students[idx]->score_final<<"\t\t|";
            std::cout <<"   "<<students[idx]->faults<<"\t|\n";
        }
    }
}

void show_unsuccesful_students(student_t *students[]){
    std::cout << "Showing Unsccesful students \n";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]!=NULL){
            if (students[idx]->score_final<7.0){
                std::cout << students[idx]->name << ": " << students[idx]->score_final << "\n";
            }
        }
    }
}

void show_succesful_students(student_t *students[]){
    std::cout << "Showing Succesful students \n";
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]!=NULL){
            if (students[idx]->score_final>=7.0){
                std::cout << students[idx]->name << ": " << students[idx]->score_final << "\n";
            }
        }
    }
}

void delete_student(student_t *students[]){
    std::string delete_student;
    std::cout << "Name of student to be deleted: ";
    std::cin >> delete_student;
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]!=NULL){
            if (students[idx]->name==delete_student){
                delete(students[idx]);
                students[idx] = NULL;
                return;
            }
        }
    }
    std::cout << "Error, Can´t delete student, Student not found \n";
}

void show_student_more_faults(student_t *students[]){
    int more_faults=0;
    int idx_moreFaults=-1;
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]!=NULL){
            if (students[idx]->faults>more_faults){
                more_faults = students[idx]->faults;
                idx_moreFaults = idx;
            }
        }
    }
    if (idx_moreFaults>=0){
        std::cout << "Student with more faults: " << students[idx_moreFaults]->name << " " << more_faults << "\n";
    }else{
        std::cout << "Error, student is empty \n";
    }
}

void delete_all_students(student_t *students[]){
    for (int idx=0; idx<MAX_STUDENTS; idx++){
        if (students[idx]!=NULL){
            delete(students[idx]);
            students[idx] = NULL;
        }
    }
}


#endif //STUDENTS_CPP