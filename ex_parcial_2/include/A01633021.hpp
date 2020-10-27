#ifndef A01633021_HPP  
#define A01633021_HPP 

#include "OP3_Arm.hpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>

#define PI 3.14159265

typedef struct angular_coordinates_s{
    float coordinate_join1;
    float coordinate_join2;
    float coordinate_join3;
} angular_coordinates_t;

typedef struct coordinates_time_s{
    float time;
    coordinates_t coordinates;
} coordinates_time_t;

typedef struct angular_coordinates_time_s{
    float time;
    angular_coordinates_t coordinates;
} angular_coordinates_time_t;

class A01633021 : public OP3_Arm{
    private:
        std::queue<coordinates_time_t> queue_trajectory;       //Vector para guardar coordenadas de trayectoria
        std::queue<angular_coordinates_time_t> queue_joints;   //Vector para almacenar coordenadas angulares de uniones
        std::queue<coordinates_time_t> queue_efector;          //Vector para guardar coordenadas angulares de efector
        std::queue<coordinates_time_t> queue_error;            //Vector para guardar error de coordenadas 
    public:
        //Sobre escribir metodos
        A01633021(distance_t w_1, distance_t w_2, distance_t w_3, distance_t w_4, float _altura);
        void calculate_forward_kinematics();
        void calculate_inverse_kinematics();
        //Leer trayectoria de archivo de texto para guardarlo en vector
        bool read_trajectory(std::string file_name);
        //Escribir coordenadas andgulare del vector en archivo de texto
        bool write_joints(std::string file_name);
        //Escribir coordenadas de efector final en archivo de texto
        bool write_efector(std::string file_name);
        //Escribit error en coordenadas en archivo de texto
        bool write_error(std::string file_name);
        //Funciones auxiliares para calcular seno, coseno y sus inversos en grados
        double sind(float degree);      
        double cosd(float degree);
        double asind(float value);
        double acosd(float value);
        double atand(float value);
};

#endif //A01633021_HPP