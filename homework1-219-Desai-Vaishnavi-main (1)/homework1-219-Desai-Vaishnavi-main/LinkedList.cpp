#include "LinkedList.h"
using namespace std;

template<class ItemType> 
LinkedList<ItemType>::LinkedList(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType>
int LinkedList<ItemType>::getCurrentSize() const{
    return itemCount;
}

template<class ItemType> 
bool LinkedList<ItemType>::isEmpty() const{ 
    return itemCount == 0;
}

template<class ItemType>
bool LinkedList<ItemType>::add(int newPosition ,const ItemType& newEntry){ 
   
    bool valid =(newPosition >=1);
    if(valid){  
        Node<ItemType>* newNodePtr = new Node<ItemType>();
        newNodePtr->setItem(newEntry);
        newNodePtr->setNext(nullptr);
        if(newPosition==1){           

           newNodePtr->setNext(headPtr); 
           headPtr = newNodePtr;        
           
        }
        else if(newPosition>1){
            Node<ItemType>* tempPtr = headPtr;
            for(int i = 1; i <= newPosition-1; i++) {
                if(tempPtr != nullptr) {
                    tempPtr = tempPtr->getNext();
                }
            }
           newNodePtr->setNext(tempPtr->getNext());
           tempPtr->setNext(newNodePtr); 
        }
        itemCount++;
         return true;
    }
    else{
        cout<<"Invalid Option"<<endl;
        return false;
    }
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int newPosition){
    bool found = false; 
    Node<ItemType>* curPtr = headPtr;

     int count = 0;

    if(newPosition >=1 && newPosition <= itemCount){

        for(int i = 1; i <= newPosition; i++) {
            if(!found && curPtr != nullptr) {
                curPtr = curPtr->getNext();    
                found=true;          
          }
        }
                
        
        if (found){    

            if(newPosition==1){
                curPtr=headPtr;
                headPtr = curPtr->getNext();

            }

            
            else{      
                Node<ItemType>* prevPtr = headPtr;
                for(int i = 1; i <= newPosition-1; i++) {
                    if(prevPtr != nullptr) {
                        prevPtr = prevPtr->getNext();              
                    }
                }

                curPtr=prevPtr->getNext();
                prevPtr->setNext(curPtr->getNext());
                                   
            }     
        itemCount--; 
        delete curPtr;
        } 
    
    return found;
    }
    else{
        cout<<"Invalid Option"<<endl;
        return false;

    }
}

template<class ItemType>
void LinkedList<ItemType>::clear(){  
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while(headPtr != nullptr){  
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);   
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr; 
    }
}

template<class ItemType> vector<ItemType> 
LinkedList<ItemType>::toVector() const{   
    vector<ItemType> ListContents;
    Node<ItemType>* curPtr = headPtr; 
         
    for (int i = 0; i < itemCount && curPtr != nullptr; i++){
        ListContents.push_back(curPtr->getItem()); 
         curPtr = curPtr->getNext();  
     }    
return ListContents;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){ 
    clear();
}
