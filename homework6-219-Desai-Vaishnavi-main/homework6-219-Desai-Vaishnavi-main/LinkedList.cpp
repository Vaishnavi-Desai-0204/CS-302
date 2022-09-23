#ifndef LINKEDLIST
#define LINKEDLIST

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : m_first(nullptr), m_last(nullptr) {};

template <typename T>
LinkedList<T>::LinkedList(T * arr, size_t size) : m_first(nullptr), m_last(nullptr) {
    for (size_t i = 0; i < size; i++, arr++) {
        add(*arr);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & other) {
    for (std::shared_ptr<Node<T> > n = other.m_first; n != nullptr; n = n->m_next) {
        add(n->m_value);
    }
}

template <typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rhs) {
    clear();
    for (std::shared_ptr<Node<T> > n = rhs.m_first; n != nullptr; n = n->m_next) {
        add(n->m_value);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
T & LinkedList<T>::at(int index) {
    if (size() < index) {
        std::cout << "Index out of bounds \n";
    }

  std::shared_ptr<Node<T> > currentNode = m_first;
    for (size_t i = 0; i < index; i++) {
        currentNode = currentNode->m_next;
    }

    return currentNode->m_value;
}

template <typename T>
const T & LinkedList<T>::at(int index) const {
    if (size() < index) {
        std::cout << "Index out of bounds \n";
    }

    std::shared_ptr<Node<T> > currentNode = m_first;
    for (size_t i = 0; i < index; i++) {
        currentNode = currentNode->m_next;
    }

    return currentNode->m_value;
}

template <typename T>
T & LinkedList<T>::operator[](int index) {
    return at(index);
}

template <typename T>
const T & LinkedList<T>::operator[](int index) const {
    return at(index);
}

template <typename T>
int LinkedList<T>::indexOf(const T & value) const {
    if (empty()) return -1;

    int i = 0;
    for (std::shared_ptr<Node<T> > n = m_first; n != nullptr; n = n->m_next, i++) {
        if (n->m_value == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void LinkedList<T>::add(const T & value) {
    if (size() == 0) {
        std::shared_ptr<Node<T> > n = std::make_shared<Node<T> >(value);
        m_first = n;
        m_last = n;
    }
    else {
        std::shared_ptr<Node<T> > n = std::make_shared<Node<T> >(value);
        m_last->m_next = n;
        m_last = m_last->m_next;
    }
};

template <typename T>
void LinkedList<T>::insert(const T & value, int index) {
    if (size() < index) {
        std::cout << "Index out of bounds \n";
        return;
    }

    if (index == size()) {
        add(value);
    }
    else if (index == 0) {
        std::shared_ptr<Node<T> > newNode = std::make_shared<Node<T> >(value);
        newNode->m_next = m_first;
        m_first = newNode;
    }
    else {
        std::shared_ptr<Node<T> > currentNode = m_first;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->m_next;
        }

        std::shared_ptr<Node<T> > newNode = std::make_shared<Node<T> >(value);
        newNode->m_next = currentNode->m_next;
        currentNode->m_next = newNode;
    }
};

template <typename T>
T LinkedList<T>::removeAt(int index) {
    size_t count = size();
    T val = T();

    if (index >= count) {
        std::cout << "Index out of bounds \n";
        return val;
    }

    std::shared_ptr<Node<T> > removedNode;
    if (index == 0) {
        removedNode = m_first;
        val = m_first->m_value;
        m_first = m_first->m_next;
    }
    else {
        std::shared_ptr<Node<T> > currentNode = m_first;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->m_next;
        }
        removedNode = currentNode->m_next;
        if (removedNode == m_last) {
            m_last = currentNode;
        }
        val = removedNode->m_value;
        currentNode->m_next = currentNode->m_next->m_next;
    }

    delete removedNode;
    return val;
}

template <typename T>
T LinkedList<T>::remove(const T & value) {
    T val = T();
    std::shared_ptr<Node<T> > removedNode = nullptr;

    if (size() == 0) {
        std::cout << "Index out of bounds \n";
        return val;
    }
   
    if (m_first->m_value == value) {
        removedNode = m_first;
        val = m_first->m_value;
        m_first = m_first->m_next;
    }
    else {
        std::shared_ptr<Node<T> > currentNode = m_first;
        while (currentNode->m_next != nullptr && currentNode->m_next->m_value != value) {
            currentNode = currentNode->m_next;
        }
        removedNode = currentNode->m_next;
        if (removedNode == nullptr) {
            std::cout << value << " could not be found \n";
            return val;
        }
        val = removedNode->m_value;
        currentNode->m_next = currentNode->m_next->m_next;
    }

    delete removedNode;
    return val;
}

template <typename T>
void LinkedList<T>::clear() {
    m_first = nullptr;
    m_last = nullptr; 
}

template <typename T>
size_t LinkedList<T>::size() const {
    size_t count = 0;
    for (std::shared_ptr<Node<T> > n = m_first; n != nullptr; n = n->m_next, count++);
    return count;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return size() == 0;
}



#endif