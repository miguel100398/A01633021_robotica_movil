#ifndef READ_FILE_CPP
#define READ_FILE_CPP

#include "../includes/read_file.hpp"

bool read_file(std::string file_name, double *coord, int size){
    std::string tmp_data;
    int idx = 0;
    std::ifstream rd_file(file_name);

    //check if file is open
    if (!rd_file.is_open()){
        std::cout << "Error, can´t open file to read array: " << file_name << "\n";
        return false;
    }

    //read file
    while ( getline (rd_file, tmp_data)){
        coord[idx++] = std::stod(tmp_data);
        if (idx > size){
            std::cout <<"Error, File is greater than ARR_SIZE:" << std::to_string(size) << "\n";
            return false;
        }
    }

    return true;
}

bool write_file(std::string file_name, double *array_to_write, int size){
    std::ofstream wr_file(file_name);

    //Check if file is open
    if (!wr_file.is_open()){
        std::cout << "Error, can´t open file to write array: " <<file_name<< "\n";
        return false;
    }

    //Write arrray to file
    for (int idx=0; idx<size; idx++){
        
        wr_file <<  std::setprecision(PRINT_PRECISION) << array_to_write[idx] << "\n";
    }

    return true;
}

#endif //READ_FILE_CPP