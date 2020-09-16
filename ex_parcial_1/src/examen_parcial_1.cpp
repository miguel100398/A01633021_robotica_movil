#ifndef EXAMEN_PARCIAL_1_CPP
#define EXAMEN_PARCIAL_1_CPP

#include "../includes/read_file.hpp"
#include "../includes/fourier.hpp"
#include "../includes/convolution.hpp"

#define CONV_SIZE (ARR_SIZE*2)-1

int main(){
    //Files to read accelerometer data
    std::string file_accelerometer_x = "data/accelerometer_x.txt";
    std::string file_accelerometer_y = "data/accelerometer_y.txt";
    std::string file_accelerometer_z = "data/accelerometer_z.txt";
    std::string file_filter_coefficients = "data/filtro.txt";
    //Files to store magnitude of spectrum
    std::string file_magnitude_x = "data/bode_magnitude_x.txt";
    std::string file_magnitude_y = "data/bode_magnitude_y.txt";
    std::string file_magnitude_z = "data/bode_magnitude_z.txt";
    std::string file_magnitude_filter = "data/bode_magnitude_filter.txt";
    //Files to store convolution
    std::string file_conv_x = "data/conv_x.txt";
    std::string file_conv_y = "data/conv_y.txt";
    std::string file_conv_z = "data/conv_z.txt";
    //Files to store magnitude of spectrum of convolution
    std::string file_magnitude_conv_x = "data/bode_magnitude_conv_x.txt";
    std::string file_magnitude_conv_y = "data/bode_magnitude_conv_y.txt";
    std::string file_magnitude_conv_z = "data/bode_magnitude_conv_z.txt";
    //Arrays to store original data
    double acc_x[ARR_SIZE];
    double acc_y[ARR_SIZE];
    double acc_z[ARR_SIZE];
    double filter_coeff[ARR_SIZE];
    //Arrays to store convolutions
    double conv_x[CONV_SIZE];
    double conv_y[CONV_SIZE];
    double conv_z[CONV_SIZE];
    //Arrays to store fourier transform
    std::complex<double> fourier_x[ARR_SIZE];
    std::complex<double> fourier_y[ARR_SIZE];
    std::complex<double> fourier_z[ARR_SIZE];
    std::complex<double> fourier_filter[ARR_SIZE];
    std::complex<double> fourier_conv_x[CONV_SIZE];
    std::complex<double> fourier_conv_y[CONV_SIZE];
    std::complex<double> fourier_conv_z[CONV_SIZE];
    //tmp arrays to store phase of signals
    double tmp_phase[CONV_SIZE];
    //Arrays to store magnitude of spectrum
    double magnitude_x[ARR_SIZE];
    double magnitude_y[ARR_SIZE];
    double magnitude_z[ARR_SIZE];
    double magnitude_filter[ARR_SIZE];
    double magnitude_conv_x[CONV_SIZE];
    double magnitude_conv_y[CONV_SIZE];
    double magnitude_conv_z[CONV_SIZE];

    std::cout << "Init examen parcial 1 \n";

    //Reading files
    std::cout << "Reading files \n";
    if (!read_file(file_accelerometer_x, acc_x, ARR_SIZE)){
        std::cout << "Can´t read accelerometer_x file, Exiting program \n";
        return 1;
    }
    if (!read_file(file_accelerometer_y, acc_y, ARR_SIZE)){
        std::cout << "Can´t read accelerometer_y file, Exiting program \n";
        return 1;
    }
    if (!read_file(file_accelerometer_z, acc_z, ARR_SIZE)){
        std::cout << "Can´t read accelerometer_z file, Exiting program \n";
        return 1;
    }
    if (!read_file(file_filter_coefficients, filter_coeff, ARR_SIZE)){
        std::cout << "Can´t read accelerometer_x file, Exiting program \n";
        return 1;
    }

    //Performing convolution of signals
    std::cout << "Performing convolution of signals \n";
    if (!conv(acc_x, filter_coeff, conv_x, ARR_SIZE)){
        std::cout << "Can´t perform convolution on axis x, Exiting program \n";
        return 1;
    }
    if (!conv(acc_y, filter_coeff, conv_y, ARR_SIZE)){
        std::cout << "Can´t perform convolution on axis y, Exiting program \n";
        return 1;
    }
    if (!conv(acc_z, filter_coeff, conv_z, ARR_SIZE)){
        std::cout << "Can´t perform convolution on axis z, Exiting program \n";
        return 1;
    }

    //Performing Fourier Transform
    std::cout << "Performing Fourier Transform \n";
    if (!discrete_fourier_transform(acc_x, fourier_x, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis x, Exiting program \n";
        return 1;
    }
    if (!discrete_fourier_transform(acc_y, fourier_y, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis y, Exiting program \n";
        return 1;
    }
    if (!discrete_fourier_transform(acc_z, fourier_z, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis x, Exiting program \n";
        return 1;
    }
    if (!discrete_fourier_transform(filter_coeff, fourier_filter, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis x, Exiting program \n";
        return 1;
    }
    if (!discrete_fourier_transform(conv_x, fourier_conv_x, CONV_SIZE)){
        std::cout << "Can´t perform Fourier transform on conv_x, Exiting program \n";
        return 1;
    }
    if (!discrete_fourier_transform(conv_y, fourier_conv_y, CONV_SIZE)){
        std::cout << "Can´t perform Fourier transform on conv_y, Exiting program \n";
        return 1;
    }
    if (!discrete_fourier_transform(conv_z, fourier_conv_z, CONV_SIZE)){
        std::cout << "Can´t perform Fourier transform on conv_z, Exiting program \n";
        return 1;
    }

    //Getting Magnitue of spectrum
    std::cout << "Getting magnitude of spectrum \n";
    if (!bode(fourier_x, magnitude_x, tmp_phase, ARR_SIZE)){
        std::cout << "Can´t get bode on axis_x, Exiting program \n";
        return 1;
    }
    if (!bode(fourier_y, magnitude_y, tmp_phase, ARR_SIZE)){
        std::cout << "Can´t get bode on axis_y, Exiting program \n";
        return 1;
    }
    if (!bode(fourier_z, magnitude_z, tmp_phase, ARR_SIZE)){
        std::cout << "Can´t get bode on axis_z, Exiting program \n";
        return 1;
    }
    if (!bode(fourier_filter, magnitude_filter, tmp_phase, ARR_SIZE)){
        std::cout << "Can´t get bode on filter, Exiting program \n";
        return 1;
    }
    if (!bode(fourier_conv_x, magnitude_conv_x, tmp_phase, CONV_SIZE)){
        std::cout << "Can´t get bode on conv_x, Exiting program \n";
        return 1;
    }
    if (!bode(fourier_conv_y, magnitude_conv_y, tmp_phase, CONV_SIZE)){
        std::cout << "Can´t get bode on conv_y, Exiting program \n";
        return 1;
    }
    if (!bode(fourier_conv_z, magnitude_conv_z, tmp_phase, CONV_SIZE)){
        std::cout << "Can´t get bode on conv_z, Exiting program \n";
        return 1;
    }

    //Writting files
    std::cout << "Writing output files \n";
    if (!write_file(file_magnitude_x, magnitude_x, ARR_SIZE)){
        std::cout << "Can´t write magnitude_x, Exiting \n";
        return 1;
    }
    if (!write_file(file_magnitude_y, magnitude_y, ARR_SIZE)){
        std::cout << "Can´t write magnitude_y, Exiting \n";
        return 1;
    }
    if (!write_file(file_magnitude_z, magnitude_z, ARR_SIZE)){
        std::cout << "Can´t write magnitude_z, Exiting \n";
        return 1;
    }
    if (!write_file(file_magnitude_filter, magnitude_filter, ARR_SIZE)){
        std::cout << "Can´t write magnitude_filter, Exiting \n";
        return 1;
    }
    if (!write_file(file_conv_x, conv_x, CONV_SIZE)){
        std::cout << "Can´t write conv_x, Exiting \n";
        return 1;
    }
    if (!write_file(file_conv_y, conv_y, CONV_SIZE)){
        std::cout << "Can´t write conv_y, Exiting \n";
        return 1;
    }
    if (!write_file(file_conv_z, conv_z, CONV_SIZE)){
        std::cout << "Can´t write conv_z, Exiting \n";
        return 1;
    }
    if (!write_file(file_magnitude_conv_x, magnitude_conv_x, CONV_SIZE)){
        std::cout << "Can´t write magnitude_conv_x, Exiting \n";
        return 1;
    }
    if (!write_file(file_magnitude_conv_y, magnitude_conv_y, CONV_SIZE)){
        std::cout << "Can´t write magnitude_conv_y, Exiting \n";
        return 1;
    }
    if (!write_file(file_magnitude_conv_z, magnitude_conv_z, CONV_SIZE)){
        std::cout << "Can´t write magnitude_conv_z, Exiting \n";
        return 1;
    }

    std::cout << "Examen parcial 1 finished succesfully \n";
    return 0;
}

#endif //EXAMEN_PARCIAL_1_CPP