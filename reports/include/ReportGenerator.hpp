#ifndef REPORTGENERATOR_HPP
#define REPORTGENERATOR_HPP

#include <vector>
#include <fstream>      
#include "Record.hpp"
#include "Map.hpp"

class ReportGenerator{
    protected:
        static std::vector<Record*> records;
        static Map<int> year_map;
        static Map<std::string> region_map;
        static Map<std::string> animal_map;
        static std::string data_file;
        int width_column;
        int precision;
        std::string write_file;
    public:
        //Constructor
        ReportGenerator();
        //Load records from data file
        static bool loadRecords();
        virtual void compute() = 0;
        //Clean dynamic records
        static void cleanRecords();
        //Set file to read data, default is ../data/farms.dat
        static void set_data_file(std::string file);
        //Get file to read data
        static std::string get_data_file();
        void set_width_column(int width);
        int get_width_column();
        void set_precision(int precisio);
        int get_precision();
        void set_write_file(std::string file);
        std::string get_write_file();
};

#endif //REPORTGENERATOR_HPP