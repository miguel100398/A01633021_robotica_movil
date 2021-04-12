#ifndef TEST_MAP_CPP
#define TEST_MAP_CPP 

#include "../include/Map.hpp"

int main(){
    Map<int>* map_year;
    Map<std::string>* map_region;
    Record* record1;
    Record* record2;
    Record* record3;
    //Create maps
    map_year = new Map<int>();
    map_region = new Map<std::string>();
    //Create records
    record1 = new Record(2010, "America", "Canada", "Horse", 123, 321);
    record2 = new Record(2020, "Europe", "Spain", "Cow", 321, 123);
    record3 = new Record(2010, "Europe", "Spain", "Horse", 333, 111);
    //Add records to maps
    
    map_year->add(record1->get_year(), record1);
    map_year->add(record2->get_year(), record2);
    map_year->add(record3->get_year(), record3);
    map_region->add(record1->get_region(), record1);
    map_region->add(record2->get_region(), record2);
    map_region->add(record3->get_region(), record3);
    std::cout << "Records added" << std::endl;

    //Get size of maps
    std::cout << "size map_year: " << map_year->get_size() << std::endl;
    std::cout << "size map_region: " << map_year->get_size() << std::endl;

    //Get keys of maps
    std::cout << "Keys map_year" << std::endl;
    for (int i=0; i<map_year->get_keys().size(); i++){
        std::cout << "Key[" << i <<"]: " << map_year->get_keys()[i] << std::endl;
    }
    std::cout << "Keys map_region" << std::endl;
    for (int i=0; i<map_region->get_keys().size(); i++){
        std::cout << "Key[" << i <<"]: " << map_region->get_keys()[i] << std::endl;
    }

    //Modify 1 key
    map_year->get_keys()[0] = 2015;
    std::cout << "Keys map_year" << std::endl;
    for (int i=0; i<map_year->get_keys().size(); i++){
        std::cout << "Key[" << i <<"]: " << map_year->get_keys()[i] << std::endl;
    }


    std::cout << "Key 2015 values" << std::endl;
    for (int i=0; i<(*map_year)[2015].size(); i++){
        std::cout <<(*map_year)[2015][i]->toString();
    }
    std::cout << "Key 2020 values" << std::endl;
    for (int i=0; i<(*map_year)[2020].size(); i++){
        std::cout <<(*map_year)[2020][i]->toString();
    }
    std::cout << "Key America values" << std::endl;
    for (int i=0; i<(*map_region)["America"].size(); i++){
        std::cout <<(*map_region)["America"][i]->toString();
    }
    std::cout << "Key Europe values" << std::endl;
    for (int i=0; i<(*map_region)["Europe"].size(); i++){
        std::cout <<(*map_region)["Europe"][i]->toString();
    }

    //Modify 1 value
    (*map_region)["America"][0]->set_numFarms(555);
    std::cout << "modified element" << (*map_year)[2015][0]->toString();

    //Modify 1 Record
    record1->set_numAnimals(555);
    std::cout << "modified element" << (*map_year)[2015][0]->toString();

    //Try to access to empty key
    try{
        (*map_year)[2021];
    } catch(const char* msg){
        std::cout << msg;
    }
    


    //Delete Maps
    delete map_year;
    delete map_region;
    //Delete Records
    delete record1;
    delete record2;
    delete record3;

    return 0;
}

#endif //TEST_MAP_CPP