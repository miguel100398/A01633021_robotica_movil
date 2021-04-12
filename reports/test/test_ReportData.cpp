#ifndef TEST_REPORTDATA
#define TEST_REPORTDATA

#include "../include/ReportData.hpp"
#include "../include/AscBehaviour.hpp"
#include "../include/DescBehaviour.hpp"

int main(){
    AscBehaviour<int>* compare_int_asc;
    DescBehaviour<int>* compare_int_desc;
    AscBehaviour<std::string>* compare_string_asc;
    DescBehaviour<std::string>* compare_string_desc;
    ReportData<int>* reportdata_int_asc;
    ReportData<int>* reportdata_int_desc;
    ReportData<std::string>* reportdata_string_asc;
    ReportData<std::string>* reportdata_string_desc;

    //Create compare behaviour
    compare_int_asc = new AscBehaviour<int>();
    compare_int_desc = new DescBehaviour<int>();
    compare_string_asc = new AscBehaviour<std::string>();
    compare_string_desc = new DescBehaviour<std::string>();

    //Create report data
    reportdata_int_asc = new ReportData<int>(compare_int_asc);
    reportdata_int_desc = new ReportData<int>(compare_int_desc);
    reportdata_string_asc = new ReportData<std::string>(compare_string_asc);
    reportdata_string_desc = new ReportData<std::string>(compare_string_desc);

    //Add rows
    reportdata_int_asc->add(1, "first insertion[1]");
    reportdata_int_asc->add(2, "second insertion[2]");
    reportdata_int_asc->add(10, "third insertion[10]");
    reportdata_int_asc->add(5, "fourth insertion[5]");
    reportdata_int_asc->add(0, "fifth insertion[0]");
    reportdata_int_asc->add(20, "sixth insertion[20]");

    reportdata_int_desc->add(1, "first insertion[1]");
    reportdata_int_desc->add(2, "second insertion[2]");
    reportdata_int_desc->add(10, "third insertion[10]");
    reportdata_int_desc->add(5, "fourth insertion[5]");
    reportdata_int_desc->add(0, "fifth insertion[0]");
    reportdata_int_desc->add(20, "sixth insertion[20]");

    reportdata_string_asc->add("abc", "first insertion[abc]");
    reportdata_string_asc->add("abd", "second insertion[abd]");
    reportdata_string_asc->add("fg", "third insertion[fg]");
    reportdata_string_asc->add("eh", "fourth insertion[eh]");
    reportdata_string_asc->add("a", "fifth insertion[a]");
    reportdata_string_asc->add("za", "sixth insertion[za]");

    reportdata_string_desc->add("abc", "first insertion[abc]");
    reportdata_string_desc->add("abd", "second insertion[abd]");
    reportdata_string_desc->add("fg", "third insertion[fg]");
    reportdata_string_desc->add("eh", "fourth insertion[eh]");
    reportdata_string_desc->add("a", "fifth insertion[a]");
    reportdata_string_desc->add("za", "sixth insertion[za]");

    //Print rows
    std::cout << "reportdata_int_asc" << std::endl << *reportdata_int_asc;
    std::cout << "reportdata_int_desc" << std::endl << *reportdata_int_desc;
    std::cout << "reportdata_string_asc" << std::endl << *reportdata_string_asc;
    std::cout << "reportdata_string_desc" << std::endl << *reportdata_string_desc;


    //Delete report data
    delete reportdata_int_asc;
    delete reportdata_int_desc;
    delete reportdata_string_asc;
    delete reportdata_string_desc;

    //Delete compare behaviour
    delete compare_int_asc;
    delete compare_int_desc;
    delete compare_string_asc;
    delete compare_string_desc;

    return 0;
}

#endif //TEST_REPORTDATA