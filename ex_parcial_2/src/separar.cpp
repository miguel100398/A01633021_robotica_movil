#ifndef SEPARAR_CPP
#define SEPARAR_CPP

#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    std::string tmp_data;
    std::string tmp_value;
    std::string separar = "data/joints_1.txt";
    std::string x = "data/theta1.txt";
    std::string y = "data/theta2.txt";
    std::string z = "data/theta3.txt";

    std::ifstream separar_file(separar);
    std::ofstream x_file(x);
    std::ofstream y_file(y);
    std::ofstream z_file(z);


    //remove header
    getline(separar_file, tmp_data);

     while ( getline (separar_file, tmp_data)){
        std::stringstream ss(tmp_data);
        ss >> tmp_value;                      //get time from file
        ss >> tmp_value;                      //Get x from file
        tmp_value.erase( tmp_value.end()-1 );
        x_file << tmp_value << "\n";
        ss >> tmp_value;                       //Get y from file
        tmp_value.erase( tmp_value.end()-1 );
        y_file << tmp_value << "\n";
        ss >> tmp_value;                        //Get z from file
        z_file << tmp_value << "\n";
    }

    separar_file.close();
    x_file.close();
    y_file.close();
    z_file.close();


    return 0;
}

#endif // SEPARAR_CPP