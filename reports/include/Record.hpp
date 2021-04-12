#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>
#include <iostream>
#include <sstream>

class Record{
    private:
        int year;
        std::string region;
        std::string subRegion;
        std::string animalType;
        int numFarms;
        int numAnimals;
    public:
        //Constructors
        Record();
        Record(int year, std::string region, std::string subRegion, std::string animalType, int numFarms, int numAnimals);
        //Desctructor
        ~Record();
        //Setters
        void set_year(int year);
        void set_region(std::string region);
        void set_subRegion(std::string subRegion);
        void set_animalType(std::string animalType);
        void set_numFarms(int numFarms);
        void set_numAnimals(int numAnimals);
        //Getters
        int get_year();
        std::string get_region();
        std::string get_subRegion();
        std::string get_animalType();
        int get_numFarms();
        int get_numAnimals();
        //Methods
        std::string toString();
};

#endif //RECORD_HPP