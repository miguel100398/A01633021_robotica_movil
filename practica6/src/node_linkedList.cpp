#ifndef NODE_LINKEDLIST_CPP  
#define NODE_LINKEDLIST_CPP  

#include "../include/node_linkedList.hpp"

template <typename T> 
node_linkedList<T>::node_linkedList(){
    node = NULL;
    prev_node = NULL;
    next_node = NULL;
}

template <typename T> 
node_linkedList<T>::node_linkedList(T* actual, T* prev, T* next){
    node = actual;
    prev_node = prev;
    next_node = next;
}

template <typename T> 
node_linkedList<T>::~node_linkedList(){
    if (node!=NULL){
        delete node;
    }
    if (prev_node!=NULL){
        delete prev_node;
    }
    if (next_node!=NULL){
        delete next_node;
    }
}

template <typename T> 
T* node_linkedList<T>::getActualNode(){
    return node;
}

template <typename T> 
T* node_linkedList<T>::getPrevNode(){
    return prev_node;
}

template <typename T> 
T* node_linkedList<T>::getNextNode(){
    return next_node;
}

template <typename T> 
void node_linkedList<T>::setActualNode(T* actual){
    node = actual;
}

template <typename T> 
void node_linkedList<T>::setPrevNode(T* prev){
    prev_node = prev;
}

template <typename T> 
void node_linkedList<T>::setNextNode(T* next){
    next_node = next;
}


#endif //NODE_LINKEDLIST_CPP