#ifndef READ_FILE_TEST_CPP
#define READ_FILE_TEST_CPP

#include "../includes/read_file.hpp"

int main(){
    double arr_x[ARR_SIZE];
    double arr_y[ARR_SIZE];
    double arr_z[ARR_SIZE];
    std::string file_x = "data/accelerometer_x.txt";
    std::string file_y = "data/accelerometer_y.txt";
    std::string file_z = "data/accelerometer_z.txt";
    std::string write_x = "data/write_x.txt";
    std::string write_y = "data/write_y.txt";
    std::string write_z = "data/write_z.txt";

    std::cout << "Init read_file_test \n";

    //Read files
    std::cout << "Reading file accelerometer_x.txt \n";
    if (!read_file(file_x,arr_x, ARR_SIZE)){
        std::cout << "Error reading file x, exit program \n";
        return 1;
    }
    std::cout << "Reading file accelerometer_y.txt \n";
    if (!read_file(file_y,arr_y, ARR_SIZE)){
        std::cout << "Error reading file y, exit program \n";
        return 1;
    }
    std::cout << "Reading file accelerometer_z.txt \n";
    if (!read_file(file_z,arr_z, ARR_SIZE)){
        std::cout << "Error reading file z, exit program \n";
        return 1;
    }

    //Write Files
    std::cout << "Writing file write_x.txt \n";
    if (!write_file(write_x,arr_x, ARR_SIZE)){
        std::cout << "Error writing file x, exit program \n";
        return 1;
    }
    std::cout << "Writing file write_y.txt \n";
    if (!write_file(write_y,arr_y, ARR_SIZE)){
        std::cout << "Error writing file y, exit program \n";
        return 1;
    }
    std::cout << "Writing file write_z.txt \n";
    if (!write_file(write_z,arr_z, ARR_SIZE)){
        std::cout << "Error writing file z, exit program \n";
        return 1;
    }

    std::cout << "read_file_test executed succesfully \n";
    return 0;
}

#endif //READ_FILE_CPP