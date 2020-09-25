#ifndef SORT_CPP
#define SORT_CPP

#include <iostream>

void print_array(int *array, int array_size);
void generate_random_array(int *array, int array_size, int max_value);
void sort_array(int *src_array, int *dest_array, int array_size);

#define ARRAY_SIZE 20
#define MAX_VALUE 100

int main(){
    int src_array[ARRAY_SIZE];
    int dst_array[ARRAY_SIZE];
    srand (time(NULL));
    //Generate random array
    std::cout << "Generating random array \n";
    generate_random_array(src_array, ARRAY_SIZE, MAX_VALUE);
    //Print original array
    std::cout << "Printing original array \n";
    print_array(src_array, ARRAY_SIZE);
    //Sort array
    std::cout << "Sorting array \n";
    sort_array(src_array, dst_array, ARRAY_SIZE);
    //Print Sorted array
    std::cout << "Printing sorted array \n";
    print_array(dst_array, ARRAY_SIZE);
    return 0;
}

void print_array(int *array, int array_size){
    for(int idx=0; idx<array_size; idx++){
        std::cout << array[idx] << ", ";
    }
    std::cout << "\n";
}

void generate_random_array(int *array, int array_size, int max_value){
    for (int idx=0; idx<array_size; idx++){
        array[idx] = rand()%max_value;
    }
}

void sort_array(int *src_array, int *dest_array, int array_size){
    int *actual_pointer;
    int *min_pointer;
    int *last_pointer;
    last_pointer = &src_array[array_size];      //Points to a value outside of the array range
    for (int idx=0; idx<array_size;idx++){
        last_pointer--;
        actual_pointer = src_array;
        min_pointer = src_array;
        while (actual_pointer<=last_pointer){
            if (*actual_pointer<*min_pointer){
                min_pointer = actual_pointer;
            }
            actual_pointer++;
        }
        dest_array[idx] = *min_pointer;
        *min_pointer = *last_pointer;
    }
}

#endif