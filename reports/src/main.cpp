#ifndef MAIN_CPP
#define MAIN_CPP

#include "../include/Control.hpp"

int main(){
    Control control("../data/farms.dat", "../data/reportRegion(2.1).txt", "../data/reportCanada(2.2).txt", "../data/reportHorses(2.3).txt", 20, 3 );
    control.launch();
}

#endif //MAIN_CPP