#ifndef STATISTICS_CPP
#define STATISTICS_CPP
#include <iostream>


int mean(int *array, int array_size);
int mode(int *array, int array_size);
int median(int *array, int array_size);
int max(int *array, int array_size);
int min(int *array, int array_size);

int operation (int *array, int array_size, int (*functocall)(int*,int));

#define ARRAY_SIZE 10

int main(){
    int array[ARRAY_SIZE];
    int op;
    int result;
    std::cout << "Insert values of array \n";
    for (int idx=0; idx<ARRAY_SIZE; idx++){
        std::cout << "Insert value(" <<idx <<"): ";
        std::cin >> array[idx];
    }
    //Print introduced array
    std::cout << "Introduced array \n";
    for (int idx=0; idx<ARRAY_SIZE; idx++){
        std::cout << array[idx] <<", ";
    }
    std::cout << "\n";
    //Introduce operation
    std::cout <<"Introduce operation \n";
    std::cout <<"1=mean, 2=mode, 3=median, 4=max, 5=min \n";
    std::cin >> op;
    if ((op<1)||(op>5)){
        std::cout << "Invalid operation, Exit program \n";
        return 1;
    }
    switch(op){
        case 1: 
            result = operation(array, ARRAY_SIZE, mean);
            break;
        case 2: 
            result = operation(array, ARRAY_SIZE, mode);
            break;
        case 3: 
            result = operation(array, ARRAY_SIZE, median);
            break;
        case 4: 
            result = operation(array, ARRAY_SIZE, max);
            break;
        case 5: 
            result = operation(array, ARRAY_SIZE, min);
            break;
    }
    std::cout << "Result: " <<result<<"\n";
    return 0;
}

int operation (int *array, int array_size, int (*functocall)(int*,int)){
    return (*functocall)(array,array_size);
}

int mean(int *array, int array_size){
    int tmp_mean = 0;
    for (int idx=0; idx<array_size; idx++){
        tmp_mean += array[idx];
    }
    return tmp_mean/array_size;
}

//Algorithm from https://www.tutorialspoint.com/learn_c_by_examples/mode_program_in_c.htm
int mode(int *array, int array_size){
    int cnt;
    int cnt_max = 0;
    int tmp_mode;
    for (int idx=0; idx<array_size; idx++){
        cnt = 0;
        for (int idy=0; idy<array_size; idy++){
            if (array[idx]==array[idy]){
                cnt++;
            }
        }
        if (cnt>cnt_max){
            cnt_max=cnt;
            tmp_mode = array[idx];
        }
    }
    return tmp_mode;
}

int median(int *array, int array_size){
    if (array_size%2){
        return (array[array_size]+array[array_size-1])/2;
    }else{
        return array[array_size/2];
    }
}

int max(int *array, int array_size){
    int tmp_max = array[0];
    for (int idx=1; idx<array_size; idx++){
        if (array[idx]>tmp_max){
            tmp_max = array[idx];
        }
    }
    return tmp_max;
}

int min(int *array, int array_size){
    int tmp_min = array[0];
    for (int idx=1; idx<array_size; idx++){
        if (array[idx]<tmp_min){
            tmp_min = array[idx];
        }
    }
    return tmp_min;
}

#endif //STATISTICS_CPP