#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include "Node.h"

template <typename T>
class LinkedList {
    public:
        LinkedList();
        LinkedList(T * arr, size_t size);
        LinkedList(const LinkedList<T> & other);
        ~LinkedList();

        LinkedList<T> & operator=(const LinkedList<T> & rhs);

        // Access Methods
        T & at(int index);
        T & operator[](int index);
        const T & at(int index) const;
        const T & operator[](int index) const;

        
        void add(const T & value);
        void insert(const T & value, int index);
        T removeAt(int index);
        T remove(const T & value);
        void clear();
		
        int indexOf(const T & value) const;
        size_t size() const;
      
        bool empty() const;
      
    private:
        std::shared_ptr<Node<T> > m_first;
        std::shared_ptr<Node<T> > m_last;
};

#include "LinkedList.cpp"

#endif