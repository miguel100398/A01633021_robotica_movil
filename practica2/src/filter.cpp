#include <iostream>
#include <string>
#include <math.h>
#include <unistd.h>

#define t 0.1       //s
#define t_max 20    //s
#define num_samples (int) (t_max/t)     //200 samples

double average_array(double *array);

int main(){
    int t_idx = 0;
    double sin_signal[num_samples];      //200 samples
    double noise_signal[num_samples];    //200 samples
    double sin_noise_signal[num_samples];
    double sin_fitered_signal[num_samples];
    //Generate sin signal, noise signal and add them
    for (int idx=0; idx<num_samples; idx++){
        sin_signal[idx] = 5*sin(idx*t);           //sin signal
        noise_signal[idx] = ((double)(rand()%2000)/1000)-1;       //random noise [-1,1] with 3 decimals
        sin_noise_signal[idx] = sin_signal[idx] + noise_signal[idx];   //add signals
        sin_fitered_signal[idx] = 0;
    }
    
    //table header
    std::cout << "|  time  |\t|original|\t|  noise |\t|filtered|\n";
    //first 10 samples
    for (t_idx; t_idx<10;t_idx++){
        std::cout << "|"<<std::to_string(t*t_idx)<<"|\t|"<<std::to_string(sin_signal[t_idx])<<"|\t|"<<std::to_string(sin_noise_signal[t_idx])<<"|\t|"<<std::to_string(sin_fitered_signal[t_idx])<<"|\n";
        usleep(100000);     //sleep for 0.1s
    }
    for (t_idx; t_idx<num_samples; t_idx++){
        sin_fitered_signal[t_idx] = average_array(&sin_noise_signal[t_idx-10]);
        std::cout << "|"<<std::to_string(t*t_idx)<<"|\t|"<<std::to_string(sin_signal[t_idx])<<"|\t|"<<std::to_string(sin_noise_signal[t_idx])<<"|\t|"<<std::to_string(sin_fitered_signal[t_idx])<<"|\n";
        usleep(100000);     //sleep for 0.1s
    }

    return 0;
}

double average_array(double *array){
    double accum = 0;
    for (int idx=0; idx<10; idx++){
        accum += array[idx];
    }
    return accum/10;
}