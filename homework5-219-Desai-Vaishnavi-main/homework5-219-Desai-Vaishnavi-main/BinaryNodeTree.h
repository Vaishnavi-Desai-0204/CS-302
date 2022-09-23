#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include <string>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
   BinaryNode<ItemType>* rootPtr;
   
protected:
   
   int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
   int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
   void destroyTree(BinaryNode<ItemType>* subTreePtr);
   BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNodePtr);
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,const ItemType target, bool& success);
   
   BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);   
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;
   BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
 
   void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   
public:
   BinaryNodeTree();
   BinaryNodeTree(const ItemType& rootItem);
   BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr);
   BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
   ~BinaryNodeTree();
   
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   ItemType getRootData() const;
   void setRootData(const ItemType& newData);
   bool add(const ItemType& newData); // Adds a node
   bool remove(const ItemType& data); // Removes a node
   void clear();
   ItemType getEntry(const ItemType& anEntry) const;
   bool contains(const ItemType& anEntry) const;
   
   void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;
   
   BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree
#include "BinaryNodeTree.cpp"
#endif
