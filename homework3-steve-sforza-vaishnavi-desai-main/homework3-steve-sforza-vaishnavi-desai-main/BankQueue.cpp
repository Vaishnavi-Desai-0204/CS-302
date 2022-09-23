#include "BankQueue.h"
#include <iostream>

using namespace std;

template <class ItemType>
BankQueue<ItemType>::BankQueue()
{
    number_of_items = 0;
    front = 0;
    back = -1;
}

template <class ItemType>
bool BankQueue<ItemType>::is_empty() const
{
    return number_of_items == 0;
}

template <class ItemType>
bool BankQueue<ItemType>::enqueue(const ItemType& new_entry)
{
    if (number_of_items < MAX_QUEUE)
    {
        back = (back + 1) % MAX_QUEUE;
        my_queue[back] = new_entry;
        number_of_items++;
        return true;
    }
    else
    {
        cout << "Queue is full." << endl;
        return false;
    }

}

template <class ItemType>
bool BankQueue<ItemType>::dequeue()
{
    if (!is_empty())
    {
        front = (front + 1) % MAX_QUEUE;
        number_of_items--;
        return true;
    }
    else
    {
        cout << "Queue is empty." << endl;
        return false;
    }
}

template <class ItemType>
ItemType BankQueue<ItemType>::peek_front() const
{
    if (!is_empty())
        return my_queue[front];
    else
    {
        cout << "Queue is empty." << endl;
    }

}

template <class ItemType>
BankQueue<ItemType>::~BankQueue()
{

}