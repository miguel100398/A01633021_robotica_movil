#ifndef STUDENTS_HPP
#define STUDENTS_HPP

#include <string>

class students {
    private:
        std::string student_name;
        float score_partial1;
        float score_partial2;
        float score_final;
        int faults;
    public:
        students();
        students(std::string name, float partial1, float partial2, float final);
        ~students();
        std::string getName();
        float getScorePartial1();
        float getScorePartial2();
        float getScoreFinal();
        int getFaults();
        void addFaults(int add_faults);

};

#endif //STUUDENTS_HPP