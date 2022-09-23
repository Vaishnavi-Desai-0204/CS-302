#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>


template <typename T>
class Node {
    public:
        Node();
        Node(const T & val);
        Node(const std::shared_ptr<Node<T> > node);

        std::shared_ptr<Node<T> > m_next;
        T m_value;
};

#include "Node.cpp"

#endif