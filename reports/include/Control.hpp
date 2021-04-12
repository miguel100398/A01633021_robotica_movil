#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <vector>
#include "ReportGenerator.hpp"
#include "ReportRegion.hpp"
#include "ReportCanadaRegion.hpp"
#include "ReportHorses.hpp"

class Control{
    protected:
        std::vector<ReportGenerator*> reports;
        std::string file_reportRegion;
        std::string file_reportCanada;
        std::string file_reportHorses;
        std::string file_data;
        int precision;
        int column_width;
        void create_reports();
    public:
        Control();
        Control(std::string file_data, std::string file_region, std::string file_canda, std::string file_horses, int column_width, int precision);
        ~Control();
        void launch();
};

#endif //CONTROL_HPP
