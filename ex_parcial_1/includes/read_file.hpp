#ifndef READ_FILE_HPP
#define READ_FILE_HPP

#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>          //set precision of cout

#define ARR_SIZE 613
#define PRINT_PRECISION 17  //Decimal digits to be printed in the file

bool read_file(std::string file_name, double *coord, int size);
bool write_file(std::string file_name, double *array_to_write, int size);

#endif //READ_FILE_HPP