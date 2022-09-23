#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

template<class ItemType>
class QueueInterface 
{
    public:
        virtual bool is_empty() const = 0;
        virtual bool enqueue(const ItemType& new_entry) = 0;
        virtual bool dequeue() = 0;
        virtual ItemType peek_front() const = 0;
        virtual ~QueueInterface() { }
};

#endif