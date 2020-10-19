#ifndef GROUP_HPP
#define GROUP_HPP

#include "students.hpp"
#include <iostream>

#define MAX_STUDENTS 10

class group{
    private:
        students* stud[MAX_STUDENTS];    //Array to store students
        int actual_students;             //Number of students stored in class
    public:
        group();
        ~group();
        bool addStudent();
        void showAllStudents();
        void showUnsuccesfulStudents();
        void showSuccesfulStudents();
        bool deleteStudent();
        void showStudentWithMoreFaults();
        bool AddStudentFault();

};


#endif // GROUP_HPP