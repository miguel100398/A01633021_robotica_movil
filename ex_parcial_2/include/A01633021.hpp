#ifndef A01633021_HPP  
#define A01633021_HPP 

#include "OP3_Arm.hpp"
#include <iostream>
#include <math.h>

#define PI 3.14159265

class A01633021 : public OP3_Arm{
    public:
        //Sobre escribir metodos
        A01633021(distance_t w_1, distance_t w_2, distance_t w_3, distance_t w_4, float _altura);
        void calculate_forward_kinematics();
        void calculate_inverse_kinematics();
        //Auxiliar functions to calculate sin and cos in degrees
        double sind(float degree);      
        double cosd(float degree);
        double asind(float value);
        double acosd(float value);
        double atand(float value);
};

#endif //A01633021_HPP