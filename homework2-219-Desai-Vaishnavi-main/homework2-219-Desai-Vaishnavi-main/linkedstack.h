#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>{
private:
	Node<ItemType>* headPtr; 
	static const int DEFAULT_CAPACITY = 100;
	int top; // Current count of LinkedStack items
	Node<ItemType>* getNodeAt() const; 
public:
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType>& aStack);

	bool isEmpty() const ;
    bool push(const ItemType& newEntry);
    bool pop()  ;
    ItemType peek() const;
    
};

#include "linkedstack.cpp"
#endif