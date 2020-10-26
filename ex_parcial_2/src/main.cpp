#ifndef MAIN_CPP
#define MAIN_CPP  

#include "../include/A01633021.hpp"

int main(){
    A01633021 *robot = new A01633021();

    robot->calculate_forward_kinematics();
    robot->calculate_inverse_kinematics();

    delete robot;
    return 0;
}

#endif // MAIN_CPP