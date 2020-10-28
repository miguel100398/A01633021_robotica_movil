#ifndef MAIN_CPP
#define MAIN_CPP  

#include "../include/A01633021.hpp"
#include <iostream>

int main(){
    // Parametros robot
    distance_t w_1 = {.dx=-3.95, .dy=6.44, .dz=0.0304, .dist=7.5549};
    distance_t w_2 = {.dx=-1.161, .dy=8.85, .dz=0.9696, .dist=9.0474};
    distance_t w_3 = {.dx=-1.161, .dy=17.89, .dz=0.9796, .dist=17.989};
    distance_t w_4 = {.dx=-3.95, .dy=32.541, .dz=-13.153, .dist=32.8062};
    //tiempo de muestreo
    float time_m = 0.01;
    //Archivos para guardar datos
    std::string trajectory_files[5]     = {"trajectory_1.txt", "trajectory_2.txt", "trajectory_3.txt", "trajectory_4.txt", "trajectory_5.txt"};
    std::string joints_files[5]         = {"joints_1.txt", "joints_2.txt", "joints_3.txt", "joints_4.txt", "joints_5.txt"};
    std::string efector_files[5]        = {"efector_1.txt", "efector_2.txt", "efector_3.txt", "efector_4.txt", "efector_5.txt"};
    std::string error_files[5]          = {"error_1.txt", "error_2.txt", "error_3.txt", "error_4.txt", "error_5.txt"};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, 7);
    
    delete robot;
    return 0;
}



#endif // MAIN_CPP