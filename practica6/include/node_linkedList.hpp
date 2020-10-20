#ifndef NODE_LINKEDLIST_HPP  
#define NODE_LINKEDLIST_HPP  

#include <unistd.h>

template <typename T> 
class node_linkedList{
    private:
        T* data;
        node_linkedList<T>* prev_node;
        node_linkedList<T>* next_node;
    public:
        node_linkedList();
        node_linkedList(T* actual, node_linkedList<T>* prev, node_linkedList<T>* next);
        ~node_linkedList();
        T* getData();
        node_linkedList<T>* getPrevNode();
        node_linkedList<T>* getNextNode();
        void setData(T* actual);
        void setPrevNode(node_linkedList<T>* prev);
        void setNextNode(node_linkedList<T>* next);
};

#include "../src/node_linkedList.tpp"


#endif // NODE_LINKEDLIST_HPP