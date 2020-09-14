#ifndef READ_FILE_TEST_CPP
#define READ_FILE_TEST_CPP

#include "../includes/read_file.hpp"

int main(){
    double arr_x[ARR_SIZE];
    double arr_y[ARR_SIZE];
    double arr_z[ARR_SIZE];
    std::string file_x = "accelerometer_x.txt";
    std::string file_y = "accelerometer_y.txt";
    std::string file_z = "accelerometer_z.txt";
    std::string write_x = "write_x.txt";
    std::string write_y = "write_y.txt";
    std::string write_z = "write_z.txt";

    std::cout << "Init read_file_test \n";

    //Read files
    std::cout << "Reading file accelerometer_x.txt \n";
    if (!read_file(file_x,arr_x)){
        std::cout << "Error reading file x, exit program \n";
        return 1;
    }
    std::cout << "Reading file accelerometer_y.txt \n";
    if (!read_file(file_y,arr_y)){
        std::cout << "Error reading file y, exit program \n";
        return 1;
    }
    std::cout << "Reading file accelerometer_z.txt \n";
    if (!read_file(file_z,arr_z)){
        std::cout << "Error reading file z, exit program \n";
        return 1;
    }

    //Write Files
    std::cout << "Writing file write_x.txt \n";
    if (!write_file(write_x,arr_x)){
        std::cout << "Error writing file x, exit program \n";
        return 1;
    }
    std::cout << "Writing file write_y.txt \n";
    if (!write_file(write_y,arr_y)){
        std::cout << "Error writing file y, exit program \n";
        return 1;
    }
    std::cout << "Writing file write_z.txt \n";
    if (!write_file(write_z,arr_z)){
        std::cout << "Error writing file z, exit program \n";
        return 1;
    }

    std::cout << "read_file_test executed succesfully \n";
    return 0;
}

#endif //READ_FILE_CPP