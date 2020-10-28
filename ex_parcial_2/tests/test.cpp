#ifndef TEST_CPP  
#define TESST_CPP  

#include "../include/A01633021.hpp"

int main(){
    coordinates_t coor {.x=3.001, .y=4.001, .z=5.001};
    distance_t w_1 = {.dx=-3.95, .dy=6.44, .dz=0.0304, .dist=7.5549};
    distance_t w_2 = {.dx=-1.161, .dy=8.85, .dz=0.9696, .dist=9.0474};
    distance_t w_3 = {.dx=-1.161, .dy=17.89, .dz=0.9796, .dist=17.989};
    distance_t w_4 = {.dx=-3.95, .dy=32.541, .dz=-13.153, .dist=32.8062};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, 7);
    robot->set_coor_end_efector(coor);
    robot->calculate_inverse_kinematics();
    std::cout << "union 1: " << robot->get_coor_union1() << " union 2: " << robot->get_coor_union2() << " union 3: " << robot->get_coor_union3() << "\n";
    return 0;
}

#endif // TEST_CPP  