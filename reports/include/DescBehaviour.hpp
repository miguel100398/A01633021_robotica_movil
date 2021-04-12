#ifndef DESCBEHAVIOUR
#define DESCBEHAVIOUR 

#include "CompareBehaviour.hpp"

template<typename T> class DescBehaviour: public CompareBehaviour<T>{
    public:
        bool compare (T key1, T key2);
};

template<typename T> bool DescBehaviour<T>::compare(T key1, T key2){
    return key2 < key1;
}

#endif //DESCBEHAVIOUR