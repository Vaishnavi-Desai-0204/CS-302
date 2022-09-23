#ifndef NODE
#define NODE

#include "Node.h"

template <typename T>
Node<T>::Node() : m_next(NULL), m_value(NULL) {}

template <typename T>
Node<T>::Node(const T & val) : m_next(NULL), m_value(val) {}

template <typename T>
Node<T>::Node(const std::shared_ptr<Node<T> > node) : m_next(node->m_next), m_value(node->m_value) {}

#endif