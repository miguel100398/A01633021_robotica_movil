#ifndef ASCBEHAVIOUR
#define ASCBEHAVIOUR

#include "CompareBehaviour.hpp"

template<typename T> class AscBehaviour: public CompareBehaviour<T>{
    public:
        bool compare (T key1, T key2);
};

template<typename T> bool AscBehaviour<T>::compare(T key1, T key2){
    return key2 > key1;
}

#endif //ASCBEHAVIOUR