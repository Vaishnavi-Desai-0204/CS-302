#ifndef BINARY_NODE_
#define BINARY_NODE_

template<class ItemType>
class BinaryNode {
private:
    ItemType item; 
    BinaryNode<ItemType> *leftChildPtr; // Pointer to left child
    BinaryNode<ItemType> *rightChildPtr; // Pointer to right child
public:
    BinaryNode();
    BinaryNode(const ItemType &anItem);
    BinaryNode(const ItemType& anItem, BinaryNode<ItemType> *leftPtr, BinaryNode<ItemType> *rightPtr);

    ItemType getItem() const;
    void setItem(const ItemType& anItem);
    bool isLeaf() const;

    BinaryNode<ItemType> *getLeftChildPtr() const;
    BinaryNode<ItemType> *getRightChildPtr() const;

    void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
    void setRightChildPtr(BinaryNode<ItemType> *rightPtr);
}; // end BinaryNode
#include "BinaryNode.cpp"
#endif