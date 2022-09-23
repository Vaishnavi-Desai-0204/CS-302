
    #include "PriorityQueue.h"
    #include <iostream>
    using namespace std;

	 template <class ItemType>
    PriorityQueue<ItemType>::PriorityQueue(){
    number_of_items = 0;
    front = -1;
    back = -1;
    }

	template <class ItemType>
    bool PriorityQueue<ItemType>:: is_empty() const {
       return number_of_items == 0;
    }

template <class ItemType>
bool PriorityQueue<ItemType>:: enqueue(const ItemType& new_entry){ //Enqueue function to insert new_entry and its priority in queue

	int i;
	if((front==0)&&(back==MAX-1)){ //Check if Queue is full
		return false;
    }
	else
	{
		if(front==-1)//if Queue is empty
		{
			front = back = 0;
			pqueue[back] = new_entry;
		

		}
    
		else if(back == MAX-1)//if there there is some elemets in Queue
		{
			for(i=front;i<=back;i++) { 
                                pqueue[i-front] = pqueue[i]; 
                               
                                back = back-front; 
                                front = 0;
                                for(i = back;i>front;i--){
                                    if( pqueue[i]>new_entry )
                                    {
                                        pqueue[i+1] = pqueue[i];
                                        
                                    }
                                    else{
                                        break;
                                    }
                                    pqueue[i+1] = new_entry;
                                    
                                    back++;
				}
			}
		}
		else
		{
			for(i = back;i>=front;i--)
			{
				if(pqueue[i]>new_entry)
				{
					pqueue[i+1] = pqueue[i];
						
				}
				else{
					break;
                }
			}
			pqueue[i+1] = new_entry;
			
			back++;
		}	
		number_of_items ++;
		return true;
	}

}

template <class ItemType>   
 bool PriorityQueue<ItemType>::dequeue() //remove the new_entry from front
{
	if(front == -1)
	{
	cout<<"Queue is Empty";
    return false;
	}	
	else
	{
	
		if(front==back){
			front = back = -1;
			number_of_items--;
		}
		else{
			front++;
			number_of_items--;
		}
		return true;
	}
}
template <class ItemType> 

ItemType PriorityQueue<ItemType>:: peek_front() const{
    return pqueue[front];
}