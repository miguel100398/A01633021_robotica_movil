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
    coordinates_t coor {.x=3.001, .y=4.001, .z=5.001};
    distance_t w_1 = {.dx=-3.95, .dy=6.44, .dz=0.0304, .dist=7.5549};
    distance_t w_2 = {.dx=-1.161, .dy=8.85, .dz=0.9696, .dist=9.0474};
    distance_t w_3 = {.dx=-1.161, .dy=17.89, .dz=0.9796, .dist=17.989};
    distance_t w_4 = {.dx=3.95, .dy=32.541, .dz=-13.153, .dist=32.8062};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, 1.357);
    
    
    std::cout << "Testing point 1\n";
    test_point(robot, 0, 0, 0);
    test_inverse(robot);
    test_direct(robot);
    std::cout << "Testing point 2\n";
    test_point(robot, 90, 45, 90);
    test_inverse(robot);
    test_direct(robot);
    std::cout << "Testing point 3\n";
    test_point(robot, 90, -90, 90);
    test_inverse(robot);
    test_direct(robot);
    
    std::cout << "Testing point 4\n";
    test_point(robot, 90, 90, 90);
    test_inverse(robot);
    test_direct(robot);
    
    std::cout << "Testing point 5\n";
    test_point(robot, 0, -90, 0);
    test_inverse(robot);
    test_direct(robot);
    
    std::cout << "Testing point 6\n";
    test_point(robot, 0, -90, 45);
    test_inverse(robot);
    test_direct(robot);
    std::cout << "Testing point 7\n";
    test_point(robot, 45, -45, 45);
    test_inverse(robot);
    test_direct(robot);
    std::cout << "Testing point 8\n";
    test_point(robot, 30, -27, 15);
    test_inverse(robot);
    test_direct(robot);
    std::cout << "Testing point 9\n";
    test_point(robot, -36, -50, 31);
    test_inverse(robot);
    test_direct(robot);
    std::cout << "Testing point 10\n";
    test_point(robot, -90, -8, 46);
    test_inverse(robot);
    test_direct(robot);
    



    return 0;
}

#endif // TEST_CPP  