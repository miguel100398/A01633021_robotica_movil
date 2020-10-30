#ifndef A01633021_CPP  
#define A01633021_CPP  

#include "../include/A01633021.hpp"
#include <string>


A01633021::A01633021(distance_t w_1, distance_t w_2, distance_t w_3, distance_t w_4, float _altura) : OP3_Arm(w_1, w_2, w_3, w_4, _altura){

}


/*
void A01633021::calculate_forward_kinematics(){
    float d1, d2, d3, d4, d5, d6;
    float angle4, angle5;
    float l1, l2;       //Distancia eje del punto 2 a 3 y de punto 3 a 4
    //Calcular distancia ejes
    l1 = dis_w_p3.dy - dis_w_p2.dy;
    l2 = dis_w_p4.dy - dis_w_p3.dy;
    d2 = altura;
    //Encontrar distancia d3
    d3 = sind(coor_union2) * l1;
    //Encontrar angulo 4
    angle4 = 180 - ( coor_union2 + 90); 
    //Encontrar angulo 5
    angle5 = coor_union3 - angle4;
    //Encontrar d6
    d6 = cosd(angle5) * l2;
    //Encontrar Z de efector final
    coor_end_efector.z = (d2 + d3 - d6) * cosd(coor_union1);
    //Encontrar d4
    d4 = cosd(coor_union2-180) * l1;
    //Encontrar d5
    d5 = sind(angle5) * l2; 
    //Calcular d1
    d1 = d4 + d5;
    //Encontrar x de efector final
    coor_end_efector.x = (sind(coor_union1)*d1); //+ dis_w_p2.dx;
    coor_end_efector.y = cosd(coor_union1)*d1; //+ dis_w_p2.dy;
    //Calcular coordenadas de uniones
}
*/

/*
void A01633021::calculate_forward_kinematics(){
    //Declarar variables
    float ang1;
    float ang2;
    float ang3;
    float ang4;
    float ang5;
    float l1;
    float l2;
    float zmax;
    float zmax2;
    float ymax;
    float xmax;
    float d1;
    float d2;
    float d3;
    float d4;
    float d5;
    float r;
    //Datos conocidos
    ang1 = coor_union1;
    ang2 = coor_union2;
    ang3 = coor_union3;
    l1 = 5;//9.3757;//dis_w_p3.dy - dis_w_p2.dy;
    l2 = 5;//14.641;//dis_w_p4.dy - dis_w_p3.dy;
    //Calcular ang4
    ang4 = ang3+0;
    ang5 = ang3 + ang2;
    //Calcular d1
    d1 = cosd(0)*l1;
    //Calcular d2
    d2 = sind(0)*l1;
    //calcular d3
    d3 = cosd(ang4)*l2;
    //calcular d4
    d4 = sind(ang4)*l2;
    d5 = sind(ang5)*l2;
    //calcular zmax
    zmax = sind(ang2)*l1+d5;
    zmax2 = sind(0)*l1+d4;
    //calcular xmax y ymax
    xmax = d1+d3;
    ymax = d1+d3;
    //calcular r
    r = sqrt((xmax*xmax)+(zmax2*zmax2));
    //calcular x
    coor_end_efector.x = sind(ang1)*sind(ang2)*xmax +cosd(ang2)*sind(ang1)*d4;//+ 2.95;
    //calcular y
    coor_end_efector.y = cosd(ang2)*ymax + sind(-ang2)*d4; //+ dis_w_p2.dy;
    //calcualr z
    coor_end_efector.z = cosd(ang1)*zmax; //+ altura;

    //std::cout<< "ang4: " << ang4 << " d1: " << d1 << " d2: " << d2 << " d3: " << d3 << " d4: " << d4 << " xmax: " << xmax << " ymax: " << ymax << " zmax: " << zmax << " r: " << r << "\n";
}
*/

void A01633021::calculate_forward_kinematics(){
    float ang1;
    float ang2;
    float ang3;
    float ang4;
    float ang5;
    float d1;
    float d2;
    float d3;
    float d4;
    float d5;
    float d6;
    float l1;
    float l2;
    float x;
    float y;
    float z;

    ang1 = coor_union1;
    ang2 = coor_union2;
    ang3 = 180-coor_union3;
    l1 = 9.3757;//dis_w_p3.dy - dis_w_p2.dy;
    l2 = 14.641;//dis_w_p4.dy - dis_w_p3.dy;
    d2 = 0;



    d3 = sind(ang2)*l1;
    ang4 = 180 - (ang2 + 90);
    ang5 = ang3 - ang4;
    d6 = cosd(ang5) * l2;


    z = d2 +d3 -d6;

    d4 = cosd(ang2)*l1;
    d5 = sind(ang5)*l2;
    d1 = d4+d5;

    if (ang1==90){      //Plano horizontal
        x = z;
        y = d1;
        z = 0;
    }else{
        x = sind(ang1)*d1;
        y = cosd(ang1)*d1;
    }

    

    coor_end_efector.x = x + dis_w_p2.dx;
    coor_end_efector.y = y + dis_w_p2.dy;
    coor_end_efector.z = z + altura;

    //std::cout<< "d1: " << d1 << " d2: " << d2 << " d3: " << d3 << " d4: "  << d4 << " d5: " << d5 << " d6: " << d6 << " ang3: " << ang3 << " ang4 " << ang4 << " ang5 " << ang5 << "\n";
}

/*
void A01633021::calculate_inverse_kinematics(){
    float l1, l2;
    float alfa;
    float x, y, z, r, b;
    l1 = dis_w_p3.dy - dis_w_p2.dy;
    l2 = dis_w_p4.dy - dis_w_p3.dy;
    //Obtener referencias relativas al punto 1
    x = coor_end_efector.x - dis_w_p2.dx;
    y = coor_end_efector.y - dis_w_p2.dy;
    z = coor_end_efector.z - altura;
    //Obtener angulo de union 1
    coor_union1 = atand(y/x);
    
    //Al obtener el primer angulo se puede reducir a 2 grados de libertad
    //Obtener base de triangulo
    b = sqrt((x*x)+(y*y));
    //Obtener angulo alfa
    alfa = atand(z/b);
    //Obtener hipotenusa de triangulo
    r = sqrt((b*b)+(z*z));
    //Obtener angulo de union 2 por teorema de coseno
    coor_union2 = acosd(((r*r)+(l1*l1)-(l2*l2))/(2*l1*r))+alfa;
    //Obtener angulo de union 3 por teorema de coseno
    coor_union3 = acosd(((l2*l2)+(l1*l1)-(r*r))/(2*l1*l2));
}
*/

void A01633021::calculate_inverse_kinematics(){
    float r;
    float x;
    float y;
    float z;
    float base;
    float elbow;
    float shoulder;
    float l1;
    float l2;
    float beta;
    float alfa;
    float gama;

    l1 = 9.3757;//dis_w_p3.dy - dis_w_p2.dy;
    l2 = 14.641;//dis_w_p4.dy - dis_w_p3.dy;
 
    y = coor_end_efector.y - dis_w_p2.dy;
    x = coor_end_efector.x - dis_w_p2.dx;
    z = coor_end_efector.z - altura;

    r = sqrt((y*y)+(x*x)+(z*z));


    if (y!=0){
        base = atand(x/y);
    }else if (x!=0){
        base = 90;
    }else{
        base = 0;
    }

    if (z==0){          //Plano horizontal
        z = x;
        base = 90;
    }

    alfa = asind(z/r);
    beta = acosd(((r*r)+(l1*l1)-(l2*l2))/(2*r*l1));
    gama = acosd(((l2*l2)+(l1*l1)-(r*r))/(2*l2*l1));

    elbow = 180-gama;
    //elbow = -acosd(((r*r)-(l1*l1)-(l2*l2))/(-2*l1*l2)) + 180;
    //shoulder = alfa + atand((l2*sind(elbow))/(l1+l2*cosd(elbow)));
    shoulder = alfa + beta;


    coor_union1 = base;
    coor_union2 = shoulder;
    coor_union3 = elbow;

}

/*
void A01633021::calculate_inverse_kinematics(){
    float l1;
    float l2;
    float x;
    float y;
    float z;
    float r;
    float ang1;
    float ang2;
    float ang3;
    float ang4;
    float ang5;
    float ang6;
    float ang7;
    float ang8;
    float ang9;
    float d1;
    float d2;
    float d3;
    float d4;
    float d5;
    float d6;

    l1 = 5;//9.3757;//dis_w_p3.dy - dis_w_p2.dy;
    l2 = 5;//14.641;//dis_w_p4.dy - dis_w_p3.dy;
    x = coor_end_efector.x;// - 2.95;
    y = coor_end_efector.y;// - dis_w_p2.dy;
    z = coor_end_efector.z;// - altura;

    if ((coor_end_efector.x<0.01) && (coor_end_efector.x>=-0.01)){
        x=z;
    }

    r = sqrt((x*x)+(y*y));

    std::cout << "r: " << r << "\n";
    

    ang1 = acosd(x/r);
    std::cout << "ang1: " << ang1 << "\n";
    ang2 = acosd(y/r);
    if (x<0){
        ang2 = -ang2;
    }
    std::cout << "ang2: " << ang2 << "\n";
    if (ang1==90){
        ang3 = 0;
    } else {
        ang3 = acosd(((l1*l1)+(r*r)-(l2*l2))/(2*l1*r));
    }
    std::cout << "ang3: " << ang3 << "\n";
    if (ang2==90){
        ang4 = 0;
    }
    else {
        ang4 = acosd(((l2*l2)+(r*r)-(l1*l1))/(2*l2*r));
    }
    if (x<0){
        ang4 = -ang4;
    }
    std::cout << "ang4: " << ang4 << "\n";
    ang5 = acosd(((l2*l2)+(l1*l1)-(r*r))/(2*l2*l1));
    std::cout << "ang5: " << ang5 << "\n";
    if ((y>=0) && (x>=0)){                      //Cuadrante 1
        ang6 = 90 - ang1 - ang3;
        ang7 = 90 - ang2 - ang4;
    }
    else if (y>=0 && x<=0){                     //Cuadrante 2
        ang6 = ang1-90 + abs(ang3);
        ang7 = ang2-90 + abs(ang4);
    }
    else if (y<=0 && x<=0){                      //Cuadrantr 3
        ang6 = 180 - ang1 - ang3;
        ang7 = 180 - ang2 - ang4;
    } else{                                     //Cuadrante4
        ang6 = 180 - ang1 - ang3;
        ang7 = 180 - ang2 - ang4;
    }
    if (ang6 >90){
        ang6 = 180 - ang6;
    }
    if (x<0){
        ang6 = -ang6;
    }
    std::cout << "ang6: " << ang6 << "\n";
    std::cout << "ang7: " << ang7 << "\n";


    d1 = y * tand(ang6);
    std::cout << "d1: " << d1<< "\n";
    d2 = sqrt((y*y)+(d1*d1));
    std::cout << "d2: " << d2 << "\n";
    d3 = x - d1;
    std::cout << "d3: " << d3 << "\n";
    d4 = sqrt((l2*l2)+(d3*d3)-2*l2*d3*cos(ang7));
    std::cout << "d4: " << d4 << "\n";
    if (d4 != 0){
        ang8 = acosd(((l2*l2)+(d4*d4)-(d3*d3))/(2*l2*d4));
    } 

    ang8 = 180-ang5;

    std::cout << "ang8: " << ang8 << "\n";
    d5 = sind(ang6)*d4;
    std::cout << "d5: " << d5 << "\n";
    d6 = d3+d5;
    std::cout << "d6: " << d6 << "\n";

    if (d6==0){
        if (x==0 && y==0){
            ang9 = acosd(z/(l1+l2));
        } else{
            ang9 = 90;
        }
    } else{
        ang9 = acosd(z/d6);
    }

    if ((coor_end_efector.x<0.01) && (coor_end_efector.x>=-0.01)){
        std::cout << "Estoy aqui1\n";
        ang9 = 0;
        if (y<0.01 && y>=-0.01){
            std::cout << "Estoy aqui2\n";
            ang8 = 0;
            ang6 = 90 - acosd(z/(l1+l2));
        }
    }


    coor_union1 = ang9;
    coor_union2 = ang6;
    coor_union3 = ang8;
}
*/

void A01633021::process_trajectory(){
    float time;
    coordinates_time_t tmp_trajectory;
    angular_coordinates_time_t tmp_joints;
    coordinates_time_t tmp_efector;
    coordinates_time_t tmp_error;
        //Iterate queue
    for (int idx=0; idx<queue_trajectory.size(); idx++){
        //Obtener tiempo
        time =  queue_trajectory[idx].time;
        //Obtener coordenadas deseadas
        tmp_trajectory     = queue_trajectory[idx];
        coor_end_efector.x = tmp_trajectory.coordinates.x;  
        coor_end_efector.y = tmp_trajectory.coordinates.y;
        coor_end_efector.z = tmp_trajectory.coordinates.z;
        //Aplicar cinematica inversa
        this->calculate_inverse_kinematics();
        //Guardar coordenadas angulares calculadas
        tmp_joints.time = time;
        tmp_joints.coordinates.coordinate_join1 = coor_union1;
        tmp_joints.coordinates.coordinate_join2 = coor_union2;
        tmp_joints.coordinates.coordinate_join3 = coor_union3;
        //Calcular cinematica directa con coordenadas angulares calculadas;
        this->calculate_forward_kinematics();
        //Guardar coordenada cartesiana de efector final calculado
        tmp_efector.time = time;
        tmp_efector.coordinates.x = coor_end_efector.x;
        tmp_efector.coordinates.y = coor_end_efector.y;
        tmp_efector.coordinates.z = coor_end_efector.z;
        //Calcular error y guardar errores
        tmp_error.time = time;
        tmp_error.coordinates.x = tmp_trajectory.coordinates.x - tmp_efector.coordinates.x;
        tmp_error.coordinates.y = tmp_trajectory.coordinates.y - tmp_efector.coordinates.y;
        tmp_error.coordinates.z = tmp_trajectory.coordinates.z - tmp_efector.coordinates.z;
        //Guardar estructuras en queue
        queue_joints.push_back(tmp_joints);
        queue_efector.push_back(tmp_efector);
        queue_error.push_back(tmp_error);
    }
}

bool A01633021::read_trajectory(std::string file_name){
    std::string tmp_data;
    std::string tmp_value;
    std::ifstream rd_file(file_name);
    coordinates_time_t tmp_struct;
    //check if file is open
    if (!rd_file.is_open()){
        std::cout << "Error, can´t open file to read array: " << file_name << "\n";
        return false;
    }

     //read file
    //remove header
    getline(rd_file, tmp_data);

    while ( getline (rd_file, tmp_data)){
        std::stringstream ss(tmp_data);
        ss >> tmp_value;                      //get time from file
        tmp_struct.time = std::stof(tmp_value);
        ss >> tmp_value;                      //Get x from file
        tmp_struct.coordinates.x = std::stof(tmp_value);
        ss >> tmp_value;                       //Get y from file
        tmp_struct.coordinates.y = std::stof(tmp_value);
        ss >> tmp_value;                        //Get z from file
        tmp_struct.coordinates.z = std::stof(tmp_value);
        queue_trajectory.push_back(tmp_struct);
    }

    rd_file.close();

    return true;
}

void A01633021::clear_trajectory(){
    queue_trajectory.clear();
}

bool A01633021::write_joints(std::string file_name){
    std::ofstream wr_file(file_name);
    angular_coordinates_time_t tmp_struct;
    //check if file is open
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file to read array: " << file_name << "\n";
        return false;
    }

     //read file
    //write header
    wr_file << "time union1 union2 union3\n";

    //Escribir vector
    while (!queue_joints.empty()){
        tmp_struct = queue_joints.front();
        queue_joints.pop_front();
        wr_file << tmp_struct.time << ", " << tmp_struct.coordinates.coordinate_join1 << ", " << tmp_struct.coordinates.coordinate_join2 << ", " << tmp_struct.coordinates.coordinate_join3 << "\n";
    }

    wr_file.close();
    return true;
}

double A01633021::tand(float degree){
    return tan(degree*PI/180);
}

bool A01633021::write_efector(std::string file_name){
    std::ofstream wr_file(file_name);
    coordinates_time_t tmp_struct;
    //check if file is open
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file to read array: " << file_name << "\n";
        return false;
    }

     //read file
    //write header
    wr_file << "time x y z\n";

    //Escribir vector
    while (!queue_efector.empty()){
        tmp_struct = queue_efector.front();
        queue_efector.pop_front();
        wr_file << tmp_struct.time << ", " << tmp_struct.coordinates.x << ", " << tmp_struct.coordinates.y << ", " << tmp_struct.coordinates.z << "\n";
    }

    wr_file.close();
    return true;
}

bool A01633021::write_error(std::string file_name){
    std::ofstream wr_file(file_name);
    coordinates_time_t tmp_struct;
    //check if file is open
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file to read array: " << file_name << "\n";
        return false;
    }

     //read file
    //write header
    wr_file << "time x y z\n";

    //Escribir vector
    while (!queue_error.empty()){
        tmp_struct = queue_error.front();
        queue_error.pop_front();
        wr_file << tmp_struct.time << ", " << tmp_struct.coordinates.x << ", " << tmp_struct.coordinates.y << ", " << tmp_struct.coordinates.z << "\n";
    }

    wr_file.close();
    return true;
}

double A01633021::sind(float degree){
    return sin(degree*PI/180);
}

double A01633021::cosd(float degree){
    return cos(degree*PI/180);
}

double A01633021::asind(float value){
    return asin(value) * 180.0/PI;
}

double A01633021::acosd(float value){
    return acos(value) * 180.0/PI;
}

double A01633021::atand(float value){
    return atan(value) * 180.0/PI;
}

#endif // A01633021_CPP