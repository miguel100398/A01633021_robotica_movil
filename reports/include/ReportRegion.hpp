#ifndef REPORTREGION_HPP
#define REPORTREGION_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "ReportGenerator.hpp"
#include "ReportData.hpp"
#include "CompareBehaviour.hpp"
#include "DescBehaviour.hpp"

class ReportRegion: public ReportGenerator{
    protected:
        ReportData<float>* reportdata;
        CompareBehaviour<float>* compare;
    public:
        ReportRegion();
        ReportRegion(std::string file, int width_column, int precision);
        ~ReportRegion();
        void compute();
        void formatData(std::string region, float percentages[], float total_percentage);
        bool printReport();
};

#endif //REPORTREGION_HPP