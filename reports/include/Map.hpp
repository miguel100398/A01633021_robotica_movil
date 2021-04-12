#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include "Record.hpp"


template <typename T> class Map{
    private:
        typedef std::vector<T> key_vector_t;
        typedef std::vector<Record*> record_vector_t;
        typedef std::vector<record_vector_t> value_vector_t;
        key_vector_t keys;
        value_vector_t values;     
        int number_elements;

    public:
        Map();      //Default Constructor
        ~Map();     //Destructor
        void add(T key, Record* rec);        
        int get_size();
        key_vector_t & get_keys();
        record_vector_t & operator[] (T key);
};

/////////////////////////Constructors///////////////////////////////////////////////////////////////
template<typename T> Map<T>::Map(){
    this->number_elements = 0;
    //std::cout << "Map created" << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////Destructor//////////////////////////////////////////////////////////////////////
template<typename T> Map<T>::~Map(){
    keys.clear();
    values.clear();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////Methods//////////////////////////////////////////////////////////////////////////
template<typename T> void Map<T>::add(T key, Record* rec){
    bool exists = false;
    int index;
    record_vector_t tmp;
    //Check if  exists
    for (int i=0; i<this->number_elements; i++){
        if (this->keys[i] == key){
            exists = true;
            index = i;
            break;
        }
    }
    //Already exists
    if (exists){
        this->values[index].push_back(rec);
    } else {        //New Key
        this->keys.push_back(key);
        tmp.push_back(rec);
        this->values.push_back(tmp);
        this->number_elements++;
    }
}

template<typename T> int Map<T>::get_size(){
    return this->number_elements;
}

template<typename T> typename Map<T>::key_vector_t & Map<T>::get_keys(){
    return this->keys;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////Overload operators////////////////////////////////////////////////////////////////////
template<typename T>  typename Map<T>::record_vector_t & Map<T>::operator[] (T Key){
    bool exists = false;
    int index;
    //Check if exists
    for (int i=0; i<this->number_elements; i++){
        if (this->keys[i] == Key){
            exists = true;
            index = i;
            break;
        }
    }
    //Exists
    if (exists){
        return values[index];
    }else{
        throw "Key not found \n";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif //MAP_HPP