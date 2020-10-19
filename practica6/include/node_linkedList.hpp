#ifndef NODE_LINKEDLIST_HPP  
#define NODE_LINKEDLIST_HPP  

#include <unistd.h>

template <typename T> 
class node_linkedList{
    private:
        T* node;
        T* prev_node;
        T* next_node;
    public:
        node_linkedList();
        node_linkedList(T* actual, T* prev, T* next);
        ~node_linkedList();
        T* getActualNode();
        T* getPrevNode();
        T* getNextNode();
        void setActualNode(T* actual);
        void setPrevNode(T* prev);
        void setNextNode(T* next);
};


#endif // NODE_LINKEDLIST_HPP