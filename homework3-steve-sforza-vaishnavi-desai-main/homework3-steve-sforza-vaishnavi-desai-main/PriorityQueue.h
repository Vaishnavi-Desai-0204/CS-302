#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "QueueInterface.h"

const int MAX =100;

template<class ItemType>
class PriorityQueue : public QueueInterface<ItemType>
{
    private:
        int front, back, number_of_items;
        ItemType pqueue[MAX];
        
    public:
        PriorityQueue();
        bool is_empty() const ;
        bool enqueue(const ItemType& new_entry) ;
        bool dequeue() ;
        ItemType peek_front() const ;
        
        ~PriorityQueue() { }
};

#endif