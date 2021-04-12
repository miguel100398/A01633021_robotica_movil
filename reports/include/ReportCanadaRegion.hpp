#ifndef REPORTCANADAREGION_HPP
#define REPORTCANADAREGION_HPP

#include "ReportGenerator.hpp"
#include "ReportData.hpp"
#include "CompareBehaviour.hpp"
#include "AscBehaviour.hpp"
#include <iomanip>


class ReportCanadaRegion: public ReportGenerator{
    protected:
        ReportData<float>* reportdata;
        CompareBehaviour<float>* compare;
        std::string write_file;
    public:
        ReportCanadaRegion();
        ReportCanadaRegion(std::string file, int width_column, int precision);
        ~ReportCanadaRegion();
        void compute();
        void formatData(std::string animal, float percentage_2011, float percentage_2016, float change_percentage);
        bool printReport();

};

#endif //REPORTCANADAREGION_HPP