#ifndef MAIN_CPP
#define MAIN_CPP  

#include "../include/A01633021.hpp"
#include <iostream>

int main(){
    distance_t w_1 = {.dx=0, .dy=0, .dz=0, .dist=0};
    distance_t w_2 = {.dx=0, .dy=0, .dz=0, .dist=0};
    distance_t w_3 = {.dx=0, .dy=10, .dz=0, .dist=0};
    distance_t w_4 = {.dx=0, .dy=20, .dz=0, .dist=0};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, 7);
    coordinates_t theta_1 = {.x=0, .y=0, .z=0, .angle = 60};
    coordinates_t theta_2 = {.x=0, .y=0, .z=0, .angle = 30};
    coordinates_t theta_3 = {.x=0, .y=0, .z=0, .angle = 140};
    robot->set_coor_theta1(theta_1);
    robot->set_coor_theta2(theta_2);
    robot->set_coor_theta3(theta_3);
    robot->calculate_forward_kinematics();  
    std::cout << "X: " << robot->get_coor_end_efector().x << " ";
    std::cout << "Y: " << robot->get_coor_end_efector().y << " ";
    std::cout << "Z: " << robot->get_coor_end_efector().z << " \n";
    robot->calculate_inverse_kinematics();

    delete robot;
    return 0;
}

#endif // MAIN_CPP