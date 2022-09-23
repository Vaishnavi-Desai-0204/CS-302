#ifndef LIST_INTERFACE 
#define LIST_INTERFACE 
using namespace std;

template<class ItemType> 
class ListInterface { 
public: 
        virtual int getCurrentSize() const = 0;  
        virtual bool isEmpty() const = 0;  
        virtual bool add(int newPosition ,const ItemType& newEntry) = 0; 
        virtual bool remove(int position) = 0;    
        virtual void clear() = 0;
        virtual vector<ItemType> toVector() const = 0; 
        virtual ~ListInterface() { }
}; 
 #endif
    