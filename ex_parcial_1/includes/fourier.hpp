#ifndef FOURIER_HPP
#define FOURIER_HPP

#include <unistd.h>
#include <complex>
#include <cmath>

bool discrete_fourier_transform(double*input_arr, std::complex<double>  *output_arr, unsigned int size);
bool bode(std::complex<double> *input_arr, double *magnitude_arr, double *phase_arr, unsigned int size);

#endif //FOURIER_HPP