#include "BinaryNodeTree.h" 
#include "BinaryNode.h" 

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), 
		getHeightHelper(subTreePtr->getRightChildPtr()));
}  

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNodePtr){
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr , newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr );
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}  // end if

		return subTreePtr;
	}  // end if
}  // end balancedAdd

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;
	if (treePtr != nullptr)
	{
		// Copy node
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}  
	return newTreePtr;
}  // end copyTree

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,const ItemType target, bool& success){
   if(subTreePtr == nullptr) // not found here
      return subTreePtr;

   if (subTreePtr->getItem() == target) // found it
   {
      subTreePtr = moveValuesUpTree(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
      subTreePtr->setLeftChildPtr(targetNodePtr);
      if (!success) // no need to search right subTree
      {
         targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
         subTreePtr->setRightChildPtr(targetNodePtr);
      }  // end if
      
      return subTreePtr;
   }  // end if
}  // end removeValue

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}  // end if
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}  // end if
} 

template<class ItemType>
void BinaryNodeTree<ItemType>::	postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	} // end if
} // end postorder

template<class ItemType>
void BinaryNodeTree<ItemType>::	preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	} // end if
} // end postorder

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,const BinaryNodeTree<ItemType>* leftTreePtr,const BinaryNodeTree<ItemType>* rightTreePtr){
	rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), 
		copyTree(rightTreePtr->rootPtr));
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr){
	rootPtr = copyTree(treePtr.rootPtr);
}  // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree(){
	destroyTree(rootPtr);
}  // end destructor

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData){
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}  // end add

template<class ItemType> 
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{
	inorder(visit, rootPtr);
}  // end inorderTraverse


template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
	preorder(visit, rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{
	postorder(visit, rootPtr);
}  

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const{
	return getNumberOfNodesHelper(rootPtr);
} // end getNumberOfNodes

template<class ItemType>
int BinaryNodeTree<ItemType>::	getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
		+ getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
} // end getNumberOfNodesHelper

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem){
	if (isEmpty())
		rootPtr = new BinaryNode<ItemType>(newItem, nullptr, nullptr);
	else
		rootPtr->setItem(newItem);
} // end setRootData

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const{
	return rootPtr->getItem();
} // end getRootData


template<class ItemType>
bool BinaryNodeTree<ItemType> ::isEmpty() const{
	return rootPtr == nullptr;
}

template<class ItemType>
int BinaryNodeTree<ItemType> ::getHeight() const{
	return getHeightHelper(rootPtr);
}


template<class ItemType>
bool BinaryNodeTree<ItemType> ::remove(const ItemType& data){
	BinaryNode<ItemType>* nodePtr = nullptr;
	bool success = false;
	nodePtr = findNode(rootPtr, data, success);
	return success;
}

template<class ItemType>
void BinaryNodeTree<ItemType> ::clear(){
	destroyTree(rootPtr);
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType> ::getEntry(const ItemType& anEntry) const{
	BinaryNode<ItemType>* nodePtr = nullptr;
	bool success = false;
	nodePtr = findNode(rootPtr, anEntry, success);
	return nodePtr->getItem();
}

template<class ItemType>
bool BinaryNodeTree<ItemType> ::contains(const ItemType& anEntry) const{
	BinaryNode<ItemType>* nodePtr = nullptr;
	bool success = false;
	nodePtr = findNode(rootPtr, anEntry, success);

	return success;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType> :: findNode(BinaryNode<ItemType>* treePtr, const ItemType& target,bool& success) const{
	BinaryNode<ItemType>* nodeToPass = treePtr;
	BinaryNode<ItemType>* nodeToReturn = nullptr;
	
	if (nodeToPass == nullptr)
	{
		return nullptr;
	}
	else if (target == nodeToPass->getItem() && !success)
	{
		nodeToReturn = nodeToPass;
		success = true;
		return nodeToReturn;
	}
	else
	{
		BinaryNode <ItemType>* leftChild = nodeToPass->getLeftChildPtr();
		BinaryNode <ItemType>* rightChild = nodeToPass->getRightChildPtr();
		
		if (leftChild == nullptr && !success)
		{
			rightChild = findNode (rightChild, target, success);
			nodeToPass = rightChild;
		}
		else if (rightChild == nullptr && !success)
		{
			leftChild = findNode (leftChild, target, success);
			nodeToPass = leftChild;
		}
		return nodeToReturn;
	}
}
