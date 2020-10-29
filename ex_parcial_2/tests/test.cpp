#ifndef TEST_CPP  
#define TESST_CPP  

#include "../include/A01633021.hpp"

void test_point(A01633021 *robot, float coor1, float coor2, float coor3){
    robot->set_coor_union1(coor1);
    robot->set_coor_union2(coor2);
    robot->set_coor_union3(coor3);
    //robot->set_coor_end_efector(coor);
    robot->calculate_forward_kinematics();
    std::cout << "x: " << robot->get_coor_end_efector().x << " y: " << robot->get_coor_end_efector().y << " z: " << robot->get_coor_end_efector().z << "\n";

}

void test_point_inverse(A01633021 *robot, float x, float y, float z){
    coordinates_t coor = {.x=x, .y=y, .z=z};
    robot->set_coor_end_efector(coor);
    robot->calculate_inverse_kinematics();
    std::cout << "1: " << robot->get_coor_union1() << " 2: " << robot->get_coor_union2() << " 3: " << robot->get_coor_union3() << "\n";
}

void test_inverse(A01633021 *robot){
    robot->calculate_inverse_kinematics();
    std::cout << "1: " << robot->get_coor_union1() << " 2: " << robot->get_coor_union2() << " 3: " << robot->get_coor_union3() << "\n";
}

void test_direct(A01633021 *robot){
    robot->calculate_forward_kinematics();
    std::cout << "x: " << robot->get_coor_end_efector().x << " y: " << robot->get_coor_end_efector().y << " z: " << robot->get_coor_end_efector().z << "\n";   
}

int main(){
    coordinates_t err {.x=0, .y=0, .z=0};
    coordinates_t coor {.x=3.001, .y=4.001, .z=5.001};
    float test_x[13] = {18.1, 3.95, 19.93, 16.9, 14.6, 18.5, 6.42, 12.3, 3.95, 3.95, 10.2, 11.6, 25.3};
    float test_y[13] = {15.5, 32.54, 5.126, 3.7, 9.37, 18.2, 23.49, 5.79, 9.19, 1.26, 28, 28.3, 29.5};
    float test_z[13] = {14.1, 1.3153, 0.304, 2.3, 2.34, 0.304, 0.304, 0.304, 22.72, 18.6, 10.9, 10.5, 0.3};
    distance_t w_1 = {.dx=-3.95, .dy=6.44, .dz=0.0304, .dist=7.5549};
    distance_t w_2 = {.dx=-1.161, .dy=8.85, .dz=0.9696, .dist=9.0474};
    distance_t w_3 = {.dx=-1.161, .dy=17.89, .dz=0.9796, .dist=17.989};
    distance_t w_4 = {.dx=3.95, .dy=32.541, .dz=-13.153, .dist=32.8062};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, 1.357);
    
    for (int idx=0; idx<12; idx++){
        std::cout << "Point " << idx << "\n";
        test_point_inverse(robot, test_x[idx], test_y[idx], test_z[idx]);
        test_direct(robot);
        test_inverse(robot);
        err.x += test_x[idx]-robot->get_coor_end_efector().x;
        err.y += test_y[idx]-robot->get_coor_end_efector().y;
        err.z += test_z[idx]-robot->get_coor_end_efector().z;
    }
    
    std::cout << "Error promedio \n";
    std::cout << "x: " << err.x/12 << "\n";
    std::cout << "y: " << err.y/12 << "\n";
    std::cout << "z: " << err.z/12 << "\n";

    return 0;
}

#endif // TEST_CPP  