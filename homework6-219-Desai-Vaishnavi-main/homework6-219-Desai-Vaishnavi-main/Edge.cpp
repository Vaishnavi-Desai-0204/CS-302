
#include "Edge.h"

template <class ItemType>
Edge<ItemType>::Edge(int cost, std::shared_ptr<Vertex<ItemType> > dest){
	setDest(dest);
	setCost(cost);
}

template <class ItemType>
std::shared_ptr<Vertex<ItemType> > Edge<ItemType>::getDest() const {
	return dest; 
}

template <class ItemType>
int Edge<ItemType>::getCost() const {
	return cost; 
}

template <class ItemType>
void Edge<ItemType>::setCost(int newCost) {
	cost = newCost; 
}

template <class ItemType>
void Edge<ItemType>::setDest(std::shared_ptr<Vertex<ItemType> > newDest) {
	dest = newDest;
}
