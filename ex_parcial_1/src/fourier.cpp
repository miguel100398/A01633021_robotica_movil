#ifndef FOURIER_CPP
#define FOURIER_CPP

#include "../includes/fourier.hpp"

bool discrete_fourier_transform(double *input_arr, std::complex<double> *output_arr, unsigned int size){
    for (int idx_k=0; idx_k<size; idx_k++){
        output_arr[idx_k] = 0;
        for (int idx_n=0; idx_n<size; idx_n++){
            output_arr[idx_k] += input_arr[idx_n] * ( (cos((2*idx_k*idx_n*M_PI)/size ) ) - ((double)1i*sin((2*idx_k*idx_n*M_PI)/size) ) );
        }
    }
    return true;
}

bool bode(std::complex<double> *input_arr, double *magnitude_arr, double *phase_arr, unsigned int size){
    for (int idx=0; idx<size; idx++){
        magnitude_arr[idx] = std::abs(input_arr[idx]);
        phase_arr[idx] = std::arg(input_arr[idx]);
    }
    return true;
}


#endif //FOURIER_CPP