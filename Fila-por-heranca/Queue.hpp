#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "List.hpp"

template <typename datatype> 
class Queue : private List<datatype>{

    public:
    Queue();
    ~Queue();
    void enQueue(datatype data);
    datatype deQueue();
    void printQueue();
};

template <typename datatype>
Queue<datatype>::Queue(){}

template <typename datatype>
Queue<datatype>::~Queue(){}

template <typename datatype>
void Queue<datatype>::enQueue(datatype data){
    List<datatype>::append(data);
}

template <typename datatype>
datatype Queue<datatype>::deQueue(){
    return List<datatype>::removeFirst();
}

template <typename datatype>
void Queue<datatype>::printQueue(){
    List<datatype>::printList();
}

#endif