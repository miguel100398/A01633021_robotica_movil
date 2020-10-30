#ifndef MAIN_CPP
#define MAIN_CPP  

#include "../include/A01633021.hpp"
#include <iostream>

//Tiempo de muestreo
#define time_m 0.001
//Tiempo de simulacion de trayectorias
#define time_s 3

#define altura 1.357
#define brazo 9.3757
#define antebrazo 14.641

int main(){
    float x0 = 7;
    float y0 = 15;
    float z0 = 7;
    float delta = 1;
    coordinates_time_t coor_tmp;
    std::ofstream wr_file;
    // Parametros robot
    distance_t w_1 = {.dx=-3.95, .dy=6.44, .dz=0.0304, .dist=7.5549};
    distance_t w_2 = {.dx=-1.161, .dy=8.85, .dz=0.9696, .dist=9.0474};
    distance_t w_3 = {.dx=-1.161, .dy=17.89, .dz=0.9796, .dist=17.989};
    distance_t w_4 = {.dx=3.95, .dy=32.541, .dz=-13.153, .dist=32.8062};
    A01633021 *robot = new A01633021(w_1, w_2, w_3, w_4, altura, brazo, antebrazo);
    //Archivos para guardar datos
    std::string trajectory_files[5]     = {"data/trajectory_1.txt", "data/trajectory_2.txt", "data/trajectory_3.txt", "data/trajectory_4.txt", "data/trajectory_5.txt"};
    std::string joints_files[5]         = {"data/joints_1.txt", "data/joints_2.txt", "data/joints_3.txt", "data/joints_4.txt", "data/joints_5.txt"};
    std::string efector_files[5]        = {"data/efector_1.txt", "data/efector_2.txt", "data/efector_3.txt", "data/efector_4.txt", "data/efector_5.txt"};
    std::string error_files[5]          = {"data/error_1.txt", "data/error_2.txt", "data/error_3.txt", "data/error_4.txt", "data/error_5.txt"};
    //Generar secuencias
    //secuencia 1 Recta
    std::cout << "Generating trajectory 1\n";
    wr_file.open(trajectory_files[0]);
    //Revisar si abrio archivo
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file write trajectory " << trajectory_files[0] << "\n";
    return 1;
    }
    //header
    wr_file << "time, \tx, \ty, \tz\n";
    for (float t=0; t<time_s; t+=time_m){
        //Recta
        coor_tmp.time = t;
        coor_tmp.coordinates.x = x0+(delta*t);
        coor_tmp.coordinates.y = y0+(delta*t);
        coor_tmp.coordinates.z = z0+(delta*t);
        wr_file << t << ", " << coor_tmp.coordinates.x << ", " << coor_tmp.coordinates.y << ", " << coor_tmp.coordinates.z <<"\n";
        
    }
    wr_file.close();
    //secuencia 2 Parabola
    std::cout << "Generating trajectory 2\n";
    wr_file.open(trajectory_files[1]);
    //Revisar si abrio archivo
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file write trajectory " << trajectory_files[1] << "\n";
    return 1;
    }
    //header
    wr_file << "time, \tx, \ty, \tz\n";
    for (float t=0; t<time_s; t+=time_m){
        //Recta
        coor_tmp.time = t;
        coor_tmp.coordinates.x = x0;
        coor_tmp.coordinates.y = t;
        coor_tmp.coordinates.z = t*t;
        wr_file << t << ", " << coor_tmp.coordinates.x << ", " << coor_tmp.coordinates.y << ", " << coor_tmp.coordinates.z <<"\n";
    }
    wr_file.close();
    //secuencia 3 elipse
    std::cout << "Generating trajectory 3\n";
    wr_file.open(trajectory_files[2]);
    //Revisar si abrio archivo
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file write trajectory " << trajectory_files[2] << "\n";
    return 1;
    }
    //header
    wr_file << "time, \tx, \ty, \tz\n";
    for (float t=0; t<time_s; t+=time_m){
        //Recta
        coor_tmp.time = t;
        coor_tmp.coordinates.x = x0;
        coor_tmp.coordinates.y = y0 + 2*cos(t);
        coor_tmp.coordinates.z = z0 + sin(t);
        wr_file << t << ", " << coor_tmp.coordinates.x << ", " << coor_tmp.coordinates.y << ", " << coor_tmp.coordinates.z <<"\n";
    }
    wr_file.close();
    //secuencia 4 espiral
    std::cout << "Generating trajectory 4\n";
    wr_file.open(trajectory_files[3]);
    //Revisar si abrio archivo
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file write trajectory " << trajectory_files[3] << "\n";
    return 1;
    }
    //header
    wr_file << "time, \tx, \ty, \tz\n";
    for (float t=0; t<time_s; t+=time_m){
        //Recta
        coor_tmp.time = t;
        coor_tmp.coordinates.x = x0;
        coor_tmp.coordinates.y = 2 *(cos(t)/t);
        coor_tmp.coordinates.z = 2 *(sin(t)/t);
        wr_file << t << ", " << coor_tmp.coordinates.x << ", " << coor_tmp.coordinates.y << ", " << coor_tmp.coordinates.z <<"\n";
    }
    wr_file.close();
    //secuencia 5 hiperbola
    std::cout << "Generating trajectory 5\n";
    wr_file.open(trajectory_files[4]);
    //Revisar si abrio archivo
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file write trajectory " << trajectory_files[4] << "\n";
    return 1;
    }
    //header
    wr_file << "time, \tx, \ty, \tz\n";
    for (float t=0; t<time_s; t+=time_m){
        //Recta
        coor_tmp.time = t;
        coor_tmp.coordinates.x = x0;
        coor_tmp.coordinates.y = 0.5*t*t;
        coor_tmp.coordinates.z = 0.25*t*t*t;
        wr_file << t << ", " << coor_tmp.coordinates.x << ", " << coor_tmp.coordinates.y << ", " << coor_tmp.coordinates.z <<"\n";
    }
    wr_file.close();

    
    //Process trajectories
    for (int idx=0; idx<5; idx++){
        std::cout << "Processing trajectory " <<idx << "\n";
        if (!robot->read_trajectory(trajectory_files[idx])){
            std::cout << "Error reading trajectory file: " << trajectory_files[idx] << "\n";
            return 1;
        }
        robot->process_trajectory();
        if (!robot->write_joints(joints_files[idx])){
            std::cout << "Error writing joint file: " << joints_files[idx] << "\n";
            return 1;
        }
        if (!robot->write_efector(efector_files[idx])){
            std::cout << "Error writing efector file: " << efector_files[idx] << "\n";
            return 1;
        }
        if (!robot->write_error(error_files[idx])){
            std::cout << "Error writing error file: " << error_files[idx] << "\n";
            return 1;
        }
        robot->clear_trajectory();
    }

    delete robot;

    std::cout << "Task finished succesfully \n";
    return 0;
}



#endif // MAIN_CPP