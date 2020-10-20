#ifndef NODE_LINKEDLIST_TPP  
#define NODE_LINKEDLIST_TPP  

#include "../include/node_linkedList.hpp"

template <typename T> 
node_linkedList<T>::node_linkedList(){
    data = NULL;
    prev_node = NULL;
    next_node = NULL;
}

template <typename T> 
node_linkedList<T>::node_linkedList(T* actual, node_linkedList<T>* prev, node_linkedList<T>* next){
    data = actual;
    prev_node = prev;
    next_node = next;
}

template <typename T> 
node_linkedList<T>::~node_linkedList(){
    if (data!=NULL){
        delete data;
    }
}

template <typename T> 
T* node_linkedList<T>::getData(){
    return data;
}

template <typename T> 
node_linkedList<T>* node_linkedList<T>::getPrevNode(){
    return prev_node;
}

template <typename T> 
node_linkedList<T>* node_linkedList<T>::getNextNode(){
    return next_node;
}

template <typename T> 
void node_linkedList<T>::setData(T* actual){
    data = actual;
}

template <typename T> 
void node_linkedList<T>::setPrevNode(node_linkedList<T>* prev){
    prev_node = prev;
}

template <typename T> 
void node_linkedList<T>::setNextNode(node_linkedList<T>* next){
    next_node = next;
}


#endif //NODE_LINKEDLIST_TPP