#ifndef MAIN_CPP
#define MAIN_CPP  

#include "../include/A01633021.hpp"
#include <iostream>

int main(){
    distance_t w_1 = {.dx=-3.95, .dy=6.44, .dz=0.0304, .dist=7.5549};
    distance_t w_2 = {.dx=-1.161, .dy=8.85, .dz=0.9696, .dist=9.0474};
    distance_t w_3 = {.dx=-1.161, .dy=17.89, .dz=0.9796, .dist=17.989};
    distance_t w_4 = {.dx=-3.95, .dy=32.541, .dz=-13.153, .dist=32.8062};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, 7);
    /*
    coordinates_t theta_1 = {.x=0, .y=0, .z=0, .angle = -25};
    coordinates_t theta_2 = {.x=0, .y=0, .z=0, .angle = 45};
    coordinates_t theta_3 = {.x=0, .y=0, .z=0, .angle = -30};
    robot->set_coor_theta1(theta_1);
    robot->set_coor_theta2(theta_2);
    robot->set_coor_theta3(theta_3);
    */
    coordinates_t final = {.x=7, .y=5, .z=-5, .angle = 0};
    robot->set_coor_end_efector(final);
    robot->calculate_inverse_kinematics();
    std::cout << "theta1: " << robot->get_coor_theta1().angle << " ";
    std::cout << "theta2: " << robot->get_coor_theta2().angle << " ";
    std::cout << "theta3: " << robot->get_coor_theta3().angle << " \n";
    robot->calculate_forward_kinematics();  
    std::cout << "X: " << robot->get_coor_end_efector().x << " ";
    std::cout << "Y: " << robot->get_coor_end_efector().y << " ";
    std::cout << "Z: " << robot->get_coor_end_efector().z << " \n";

    
    delete robot;
    return 0;
}

#endif // MAIN_CPP