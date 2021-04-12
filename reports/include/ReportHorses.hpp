#ifndef REPORTHORSES_HPP
#define REPORTHORSES_HPP

#include "ReportGenerator.hpp"
#include "CompareBehaviour.hpp"
#include "DescBehaviour.hpp"
#include "ReportData.hpp"
#include <iomanip>


class ReportHorses: public ReportGenerator{
    protected:
        ReportData<int>* reportdata;
        CompareBehaviour<int>* compare;
    public:
        ReportHorses();
        ReportHorses(std::string file, int width_column, int precision);
        ~ReportHorses();
        void compute();
        void formatData(std::string region, std::string subregion, int numHorses);
        bool printReport();
};

#endif //REPORTHORSES_HPP
