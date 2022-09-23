
#include "BinarySearchTree.h"

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newEntry) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> *newNode) {
    BinaryNode<ItemType>* tempPtr;

    if (subTreePtr == nullptr) {
        return newNode;
    }  else if (subTreePtr->getItem() > newNode->getItem()) {
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else {
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}


template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
   this->preorder(visit, rootPtr);
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{
   this->inorder(visit, rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{
   this->postorder(visit, rootPtr);
}  // end postorderTraverse

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){
	this->destroyTree(rootPtr);
}  // end destructor