#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

template <class ItemType> class Vertex;

template <class ItemType>
class Edge{    
private:
	int cost;
	std::shared_ptr<Vertex<ItemType> > dest;
public:
	Edge(int cost, std::shared_ptr<Vertex<ItemType> > dest);

	std::shared_ptr<Vertex<ItemType> > getDest() const;
	int getCost() const;

	void setDest(std::shared_ptr<Vertex<ItemType> > newDest);
	void setCost(int newCost);

};

#include "Edge.cpp"
#endif