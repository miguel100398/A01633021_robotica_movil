#ifndef CONVOLUTION_CPP
#define CONVOLUTION_CPP

#include "../includes/convolution.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

bool conv(double *signal, double *filter, double *result, int size){
    int size_conv = (2*size)-1;     //assuming signal and filter are of the same length
    int idx_h;
    int half_size = size/2;
    std::cout << "size: " << std::to_string(size) << " size/2: " << std::to_string(half_size) << "\n";
    for (int idx_t=0; idx_t<size_conv; idx_t++){
        result[idx_t] = 0;
        for (int idx_i=-half_size; idx_i<=half_size; idx_i++){       //[(-size/2),(size/2)] before or after that range signal=0     
            idx_h = (idx_t-idx_i) - (half_size);              //Shifting signals size/2=0
            std::cout << "indexes: t: " << std::to_string(idx_t) << " i: " << std::to_string(idx_i) << " h: " << std::to_string(idx_h) << "\n";
            if ((idx_h<0)||(idx_h>size)){                   //Out of range
                result[idx_t] += 0;
            }else{
                result[idx_t] += signal[idx_i+half_size]*filter[idx_h];
            }
        }
    }
    return true;
}

#endif //CONVOLUTION_CPP