#ifndef A01633021_HPP  
#define A01633021_HPP 

#include "OP3_Arm.hpp"
#include <iostream>

class A01633021 : public OP3_Arm{
    public:
        //Sobre escribir metodos
        void calculate_forward_kinematics();
        void calculate_inverse_kinematics();
};

#endif //A01633021_HPP