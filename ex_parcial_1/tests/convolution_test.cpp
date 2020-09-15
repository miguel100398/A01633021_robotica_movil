#ifndef CONVOLUTION_TEST_CPP
#define CONVOLUTION_TEST_CPP

#include "../includes/convolution.hpp"
#include <iostream>
#include <unistd.h>

#define size 5

int main(){
    double signal[size] = {1,1,1,1,1};
    double filter[size] = {1,1,1,1,1};  //Two box signals to test convolution
    double result[(size*2)-1];

    std::cout << "Init convolution_test\n";
    std::cout << "Starting convolution <'n";
    if (!conv(signal, filter, result, size)){
        std::cout << "Can´t convolve signal \n";
        return 1;
    }
    std::cout << "Printing result signal\n";

    for (int idx=0; idx<(size*2)-1; idx++){
        std::cout << std::to_string(result[idx]) << ", ";
    }
    std::cout << "\n";

    std::cout << "Convolution test finished succesfully\n";
    return 0;
}

#endif //CONVOLUTION_TEST_CPP