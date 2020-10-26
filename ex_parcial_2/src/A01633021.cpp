#ifndef A01633021_CPP  
#define A01633021_CPP  

#include "../include/A01633021.hpp"

A01633021::A01633021(distance_t w_1, distance_t w_2, distance_t w_3, distance_t w_4, float _altura) : OP3_Arm(w_1, w_2, w_3, w_4, _altura){

}

void A01633021::calculate_forward_kinematics(){
    float d1, d2, d3, d4, d5, d6;
    float angle4, angle5;
    std::cout << "Calculating forward kinematics \n";
    float l1, l2;       //Distancia eje del punto 2 a 3 y de punto 3 a 4
    //Calcular distancia ejes
    l1 = dis_w_p3.dy - dis_w_p2.dy;
    l2 = dis_w_p4.dy - dis_w_p3.dy;
    d2 = altura;
    //Encontrar distancia d3
    d3 = sind(coor_theta2.angle) * l1;
    //Encontrar angulo 4
    angle4 = 180 - ( coor_theta2.angle + 90); 
    //Encontrar angulo 5
    angle5 = coor_theta3.angle - angle4;
    //Encontrar d6
    d6 = cosd(angle5) * l2;
    //Encontrar Z de efector final
    coor_end_efector.z = d2 + d3 - d6;
    //Encontrar d4
    d4 = cosd(coor_theta2.angle) * l1;
    //Encontrar d5
    d5 = sind(angle5) * l2; 
    //Calcular d1
    d1 = d4 + d5;
    //Encontrar x de efector final
    coor_end_efector.x = cosd(coor_theta1.angle)*d1 + dis_w_p2.dx;
    coor_end_efector.y = sind(coor_theta1.angle)*d1 + dis_w_p2.dy;
    //Calcular coordenadas de uniones
}

void A01633021::calculate_inverse_kinematics(){
    std::cout << "Calculating inverse kinematics \n";
}

double A01633021::sind(float degree){
    return sin(degree*PI/180);
}

double A01633021::cosd(float degree){
    return cos(degree*PI/180);
}

#endif // A01633021_CPP