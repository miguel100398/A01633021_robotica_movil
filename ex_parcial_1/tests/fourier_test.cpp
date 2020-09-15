#ifndef FOURIER_TEST_CPP
#define FOURIER_TEST_CPP

#include "../includes/fourier.hpp"
#include "../includes/read_file.hpp"

int main(){
    //arrays to read file
    double arr_x[ARR_SIZE];
    double arr_y[ARR_SIZE];
    double arr_z[ARR_SIZE];
    //arrays to store fourier transform
    std::complex<double> arr_fourier_x[ARR_SIZE];
    std::complex<double> arr_fourier_y[ARR_SIZE];
    std::complex<double> arr_fourier_z[ARR_SIZE];
    //arrays to store magnitude of fourier transform
    double arr_mag_x[ARR_SIZE];
    double arr_mag_y[ARR_SIZE];
    double arr_mag_z[ARR_SIZE];
    //arrays to store phase of fourier transform
    double arr_phase_x[ARR_SIZE];
    double arr_phase_y[ARR_SIZE];
    double arr_phase_z[ARR_SIZE];
    //Files to read data
    std::string file_x = "accelerometer_x.txt";
    std::string file_y = "accelerometer_y.txt";
    std::string file_z = "accelerometer_z.txt";
    //Files to write fourier magnitude
    std::string file_magnitude_x = "magnitude_x.txt";
    std::string file_magnitude_y = "magnitude_y.txt";
    std::string file_magnitude_z = "magnitude_z.txt";
    //Files to write fourier phase
    std::string file_phase_x = "phase_x.txt";
    std::string file_phase_y = "phase_y.txt";
    std::string file_phase_z = "phase_z.txt";

    std::cout << "Init fourier_test\n";

    std::cout << "Reading Files \n";
    if (!read_file(file_x, arr_x)){
        std::cout << "Can´t read file x, Exit program \n";
        return 1;
    }
    if (!read_file(file_y, arr_y)){
        std::cout << "Can´t read file y, Exit program \n";
        return 1;
    }
    if (!read_file(file_z, arr_z)){
        std::cout << "Can´t read file z, Exit program \n";
        return 1;
    }

    std::cout << "Performing fourier transform \n";
    if (!discrete_fourier_transform(arr_x, arr_fourier_x, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis x, Exit program \n";
        return 1;
    }
    if (!discrete_fourier_transform(arr_y, arr_fourier_y, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis y, Exit program \n";
        return 1;
    }
    if (!discrete_fourier_transform(arr_z, arr_fourier_z, ARR_SIZE)){
        std::cout << "Can´t perform Fourier transform on axis z, Exit program \n";
        return 1;
    }

    std::cout << "Getting Fourier Magnitude and phase \n";
    if (!bode(arr_fourier_x, arr_mag_x, arr_phase_x, ARR_SIZE)){
        std::cout << "Can´t get bode on axis x, Exit program \n";
        return 1;
    }
    if (!bode(arr_fourier_y, arr_mag_y, arr_phase_y, ARR_SIZE)){
        std::cout << "Can´t get bode on axis y, Exit program \n";
        return 1;
    }
    if (!bode(arr_fourier_z, arr_mag_z, arr_phase_z, ARR_SIZE)){
        std::cout << "Can´t get bode on axis z, Exit program \n";
        return 1;
    }

    std::cout << "Writing Fourier Magnitude in files \n";
    if (!write_file(file_magnitude_x, arr_mag_x)){
        std::cout << "Can´t print Fourier Magnitude on axis x, Exit program \n";
        return 1;
    }
    if (!write_file(file_magnitude_y, arr_mag_y)){
        std::cout << "Can´t print Fourier Magnitude on axis y, Exit program \n";
        return 1;
    }
    if (!write_file(file_magnitude_z, arr_mag_z)){
        std::cout << "Can´t print Fourier Magnitude on axis z, Exit program \n";
        return 1;
    }

    std::cout << "Writing Fourier Phase in files \n";
    if (!write_file(file_phase_x, arr_phase_x)){
        std::cout << "Can´t print Fourier Phase on axis x, Exit program \n";
        return 1;
    }
    if (!write_file(file_phase_y, arr_phase_y)){
        std::cout << "Can´t print Fourier Phase on axis y, Exit program \n";
        return 1;
    }
    if (!write_file(file_phase_z, arr_phase_z)){
        std::cout << "Can´t print Fourier Phase on axis z, Exit program \n";
        return 1;
    }

    std::cout << "Fourier test finished succesfully \n";

    return 0;
}

#endif // FOURIER_TEST_CPP