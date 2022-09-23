//linkedstack.cpp
//VAISHNAVI DESAI
//To implement linked based stack

template<class ItemType>
Node<ItemType>* LinkedStack<ItemType>::getNodeAt() const{ //to get node at top
	// enforce precondition
	if(!isEmpty()){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < top; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
}

template<class ItemType>//default constructor
LinkedStack<ItemType>::LinkedStack(){
    headPtr=nullptr;
     top=0;
}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack){ //copy constructor
	top = aStack.top;
	if(top > 0){
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		Node<ItemType>* oldStackPtr = aStack
        .headPtr;

		headPtr = newNodePtr;
		newNodePtr->setItem(oldStackPtr->getItem());

		Node<ItemType>* newStackPtr = nullptr;
		for(int pos = 2; pos <= top; pos++){
			oldStackPtr = oldStackPtr->getNext();
			newStackPtr = newNodePtr;
			
			newNodePtr = new Node<ItemType>();
			newStackPtr->setNext(newNodePtr);
			newNodePtr->setItem(oldStackPtr->getItem());
		}
	}
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
	return top == 0;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){//adding item on to the stack
	bool ableToPush = top < DEFAULT_CAPACITY;
	if (ableToPush){
		// Create a new node containing the new entry
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		// Attach a new node to chain
		if (isEmpty()){
			// Push new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else{
			// Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt();
			// Push new node after node to which prevPtr points
			prevPtr->setNext(newNodePtr);
		}
		top++; // Increase count of entries
	} 
	return ableToPush;
}

template<class ItemType> //removing top item of stack
bool LinkedStack<ItemType>::pop(){
	bool ableToPop = !isEmpty();
	if (ableToPop){
		Node<ItemType>* ptrToDelete = nullptr;
		if (top == 1){
			// pop the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{			
			// Point to node to pop
			ptrToDelete = getNodeAt();
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		top--; // Decrease count of entries
	}
	return ableToPop;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
	// enforce precondition
	bool canPeek = !isEmpty();
	if (canPeek){
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < top; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr->getItem();
	}
	else{
        throw "empty stack";
    }
} 





