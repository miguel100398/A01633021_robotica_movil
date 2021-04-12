#ifndef TEST_REPORTS_CPP
#define TEST_REPORTS_CPP

#include "../include/ReportRegion.hpp"
#include "../include/ReportCanadaRegion.hpp"
#include "../include/ReportHorses.hpp"

int main(){
    ReportRegion* reportregion;
    ReportCanadaRegion* reportcanadaregion;
    ReportHorses* reporthorses;

    //Create reportregion
    reportregion = new ReportRegion("../data/reportregion.txt", 20, 3);
    reportcanadaregion = new ReportCanadaRegion("../data/reportcanadaregion.txt", 20, 3);
    reporthorses = new ReportHorses("../data/reporthorses.txt", 30, 3);

    if (ReportGenerator::loadRecords()){
        std::cout << "Records loaded" << std::endl;
    }
    //Compute region statitis
    reportregion->compute();
    std::cout << "Records region computed" << std::endl;
    //Print region report
    if (reportregion->printReport()){
        std::cout << "Report region printed" << std::endl;
    }

    //Compute canada statitis
    reportcanadaregion->compute();
    std::cout << "Records canada region computed" << std::endl;
    //Print canada report
    if (reportcanadaregion->printReport()){
        std::cout << "Report canada region printed" << std::endl;
    }

     //Compute horses statitis
    reporthorses->compute();
    std::cout << "Records horses region computed" << std::endl;
    //Print horses report
    if (reporthorses->printReport()){
        std::cout << "Report horses region printed" << std::endl;
    }

    //Delete report region
    ReportGenerator::cleanRecords();
    delete reportregion;
    delete reportcanadaregion;
    delete reporthorses;

    std::cout << "Finishing test" << std::endl;

    return 0;
}

#endif //TEST_REPORTS_CPP