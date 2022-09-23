
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include <iostream>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree <ItemType>{
private:
    BinaryNode<ItemType> *rootPtr;

protected:  
    BinaryNode<ItemType> *placeNode(BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> *newNode);

public:
    BinarySearchTree();
    int getHeight() const;
    bool add(const ItemType& newEntry);
  
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    ~BinarySearchTree();
}; 
#include "BinarySearchTree.cpp"
#endif