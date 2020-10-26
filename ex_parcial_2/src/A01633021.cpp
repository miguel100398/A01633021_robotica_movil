#ifndef A01633021_CPP  
#define A01633021_CPP  

#include "../include/A01633021.hpp"

void A01633021::calculate_forward_kinematics(){
    float d1, d2, d3, d4, d5, d6;
    float angle4, angle5;
    std::cout << "Calculating forward kinematics \n";
    float l1, l2;       //Distancia eje del punto 2 a 3 y de punto 3 a 4
    //Calcular distancia ejes
    l1 = 10;//dis_w_p3.dy - dis_w_p2.dy;
    l2 = 10;//dis_w_p4.dy - dis_w_p3.dy;
    altura = 7;
    coor_theta1.angle = 60;
    coor_theta2.angle = 30;
    coor_theta3.angle = 140;
    d2 = altura;
    //Encontrar distancia d3
    d3 = sin(coor_theta2.angle) * l1;
    //Encontrar angulo 4
    angle4 = 180 - ( coor_theta2.angle + 90) 
    //Encontrar angulo 5
    angle5 = coor_theta3.angle - angle4;
    //Encontrar d6
    d6 = cos(angle5) * l2;
    //Encontrar Z de efector final
    coor_end_efector.z = d2 + d3 - d6;
    //Encontrar d4
    d4 = cos(coor_theta2.angle) * l1;
    //Encontrar d5
    d5 = sin(angle5) * l2; 
    //Calcular d1
    d1 = d4 + d5;
    //Encontrar x de efector final
    coor_end_efector.x = cos(coor_theta1.angle)*d1;
    coor_end_efector.y = sin(coor_theta1.angle)*d1;
    //Calcular coordenadas de uniones
}

void A01633021::calculate_inverse_kinematics(){
    std::cout << "Calculating inverse kinematics \n";
}

#endif // A01633021_CPP