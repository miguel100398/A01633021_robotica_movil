#ifndef CONTROL_CPP
#define CONTROL_CPP

#include "../include/Control.hpp"

Control::Control(){
    //Default values
    file_data         = "../data/farms.dat";
    file_reportRegion = "../data/reportregion.txt";
    file_reportCanada = "../data/reportcanada.txt";
    file_reportHorses = "../data/reporthorses.txt";
    column_width = 20;
    precision = 3;
    create_reports();
}

Control::Control(std::string file_data, std::string file_region, std::string file_canda, std::string file_horses, int column_width, int precision){
    this->file_data = file_data;
    file_reportRegion = file_region;
    file_reportCanada = file_canda;
    file_reportHorses = file_horses;
    this->column_width = column_width;
    this->precision = precision;
    create_reports();
}

Control::~Control(){
    ReportGenerator::cleanRecords();
    delete reports[0];
    delete reports[1];
    delete reports[2];
    reports.clear();
}

void Control::create_reports(){
    ReportGenerator::set_data_file(file_data);
    reports.push_back(new ReportRegion(file_reportRegion, column_width, precision));
    reports.push_back(new ReportCanadaRegion(file_reportCanada, column_width, precision));
    reports.push_back(new ReportHorses(file_reportHorses, column_width+15, precision));
}

void Control::launch(){
    bool exit=false;
    char key;
    if (ReportGenerator::loadRecords()){
        std::cout << "Records loaded" << std::endl;
    }else{
        std::cout << "Error cant load records" << std::endl;
        return;
    }
    while (!exit){
        //Display menu
        std::cout << "Press 1 to generate Report Region(2.1) " << std::endl;
        std::cout << "Press 2 to generate Report Canada Region(2.2) " << std::endl;
        std::cout << "Press 3 to generate Report Horses(2.3) " << std::endl;
        std::cout << "Press 0 to exit " <<std::endl;
        //Wait for key
        key = std::getchar();
        switch(key){
            case '0':
                exit = true;
                break;
            case '1':
                ReportRegion* tmp_region;
                std::cout << "Generation Report Region(2.1) " << std::endl;
                reports[0]->compute();
                tmp_region = (ReportRegion*)reports[0];
                if (!tmp_region->printReport()){
                    std::cout << "Error printing Report Region(2.1) " << std::endl;
                }
                break;
            case '2':
                ReportCanadaRegion* tmp_canada;
                std::cout << "Generation Report Canada Region(2.2) " << std::endl;
                reports[1]->compute();
                tmp_canada = (ReportCanadaRegion*)reports[1];
                if (!tmp_canada->printReport()){
                    std::cout << "Error printing Report Canada Region(2.2) " << std::endl;
                }
                break;
            case '3':
                ReportHorses* tmp_horses;
                std::cout << "Generation Report Horses(2.3) " << std::endl;
                reports[2]->compute();
                tmp_horses = (ReportHorses*)reports[2];
                if (!tmp_horses->printReport()){
                    std::cout << "Error printing Report Horses(2.3) " << std::endl;
                }
                break;
            default:
                std::cout << "Invalid option " << std::endl;
        }

    }
}


#endif //CONTROL_CPP