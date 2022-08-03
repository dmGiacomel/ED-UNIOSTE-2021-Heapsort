#include <iostream>
#include "Queue.hpp"
int main(){

    Queue<int> *queue;
    queue = new Queue<int>();

    queue->enQueue(2);
    queue->enQueue(1);
    queue->enQueue(7);
    queue->enQueue(37);
    queue->printQueue();


    std::cout << "dequeued: " << queue->deQueue() << std::endl;
    std::cout << "dequeued: " << queue->deQueue() << std::endl;
    std::cout << "dequeued: " << queue->deQueue() << std::endl;
    std::cout << "dequeued: " << queue->deQueue() << std::endl;
    std::cout << "dequeued: " << queue->deQueue() << std::endl;
    std::cout << "dequeued: " << queue->deQueue() << std::endl;

    queue->enQueue(37);    
    std::cout << "dequeued: " << queue->deQueue() << std::endl;
    queue->printQueue();

    delete(queue);

    return 0; 
}