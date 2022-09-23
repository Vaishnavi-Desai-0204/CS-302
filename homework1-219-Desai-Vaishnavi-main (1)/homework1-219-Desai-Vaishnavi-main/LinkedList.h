#ifndef LINKED_LIST
#define LINKED_LIST

#include <vector>
using namespace std;
#include "ListInterface.h"
#include "node.h"

template<class ItemType> class LinkedList: public ListInterface<ItemType> { 
private:  
    Node<ItemType>* headPtr;  
    int itemCount;
    
public:     
    LinkedList(); 
    int getCurrentSize() const;
    bool isEmpty() const; 
    bool add(int newPosition ,const ItemType& newEntry);
    bool remove(int position);
    void clear(); 
    vector<ItemType> toVector() const;
    ~LinkedList();}; 
 #include "LinkedList.cpp"
 #endif