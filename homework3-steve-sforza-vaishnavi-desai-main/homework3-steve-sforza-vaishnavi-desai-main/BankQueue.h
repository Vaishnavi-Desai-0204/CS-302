#ifndef BANK_QUEUE_H
#define BANK_QUEUE_H
#include "QueueInterface.h"
using namespace std;

const int MAX_QUEUE = 100;

template <class ItemType>
class BankQueue : public QueueInterface<ItemType>
{
    private:
        int front, back, number_of_items;
        ItemType my_queue[MAX_QUEUE];

    public:
        BankQueue();
        bool is_empty() const;
        virtual bool enqueue(const ItemType& new_entry);
        bool dequeue();
        ItemType peek_front() const;

        ~BankQueue();
};
#endif