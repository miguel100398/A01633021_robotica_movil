#ifndef TEST_RECORD_CPP
#define TEST_RECORD_CPP

#include "../include/Record.hpp"

int main(){
    Record* record1;
    Record* record2;
    //Create Record
    record1 = new Record();
    record2 = new Record(2020, "America", "Canada", "Horse", 100, 200);
    //Print record1
    std::cout << "record 1: " << record1->toString() << std::endl;
    //Print record 2
    std::cout << "record 2: " << record2->toString() << std::endl;
    //Delete records
    delete record1;
    delete record2;

    return 0;
}

#endif //TEST_RECORD_CPP