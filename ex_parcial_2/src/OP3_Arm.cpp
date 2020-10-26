#ifndef OP3_ARM_CPP  
#define OP3_ARM_CPP  

#include "../include/OP3_Arm.hpp"

OP3_Arm::OP3_Arm(){
    //Constructor default no hacer nada
}

OP3_Arm::OP3_Arm(distance_t _dis_w_p1, distance_t _dis_w_p2, distance_t _dis_w_p3){
    //Inicializar parametros constantes
    dis_w_p1 = _dis_w_p1;
    dis_w_p2 = _dis_w_p2;
    dis_w_p3 = _dis_w_p3;
}

OP3_Arm::~OP3_Arm(){
    //Nada que destruir
}
        
void OP3_Arm::set_dis_w_p1(distance_t _dis_w_p1){
    dis_w_p1 = _dis_w_p1;
}    

void OP3_Arm::set_dis_w_p2(distance_t _dis_w_p2){
    dis_w_p2 = _dis_w_p2;
}

void OP3_Arm::set_dis_w_p3(distance_t _dis_w_p3){
    dis_w_p3 = _dis_w_p3;
}

void OP3_Arm::set_dis_w_p4(distance_t _dis_w_p4){
    dis_w_p4 = _dis_w_p4;
}

void OP3_Arm::set_altura(float _altura){
    altura = _altura;
}

distance_t OP3_Arm::get_dis_w_p1(){
    return dis_w_p1;
}

distance_t OP3_Arm::get_dis_w_p2(){
    return dis_w_p2;
}

distance_t OP3_Arm::get_dis_w_p3(){
    return dis_w_p3;
}

distance_t OP3_Arm::get_dis_w_p4(){
    return dis_w_p4;
}

float OP3_Arm::get_altura(){
    return altura;
}

void OP3_Arm::set_coor_end_efector(coordinates_t _coor_end_efector){
    coor_end_efector = _coor_end_efector;
}

coordinates_t OP3_Arm::get_coor_end_efector(){
    return coor_end_efector;
}

void OP3_Arm::set_coor_theta1(coordinates_t _coor_theta1){
    coor_theta1 = _coor_theta1;
}

void OP3_Arm::set_coor_theta2(coordinates_t _coor_theta2){
    coor_theta2 = _coor_theta2;
}

void OP3_Arm::set_coor_theta3(coordinates_t _coor_theta3){
    coor_theta3 = _coor_theta3;
}

coordinates_t OP3_Arm::get_coor_theta1(){
    return coor_theta1;
}

coordinates_t OP3_Arm::get_coor_theta2(){
    return coor_theta2;
}

coordinates_t OP3_Arm::get_coor_theta3(){
    return coor_theta3;
}

void OP3_Arm::calculate_forward_kinematics(){
    //Sobre escribir en clase hija
}

void OP3_Arm::calculate_inverse_kinematics(){
    //Sobre escribir en clase hija
}


#endif // OP3_ARM_CPP