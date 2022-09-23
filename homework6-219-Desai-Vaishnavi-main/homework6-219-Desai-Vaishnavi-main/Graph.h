#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"

template <class T> class Vertex;

template <class T>
class Graph{
	
private:
	LinkedList<std::shared_ptr<Vertex<T> > > vertices;
public:
	Graph();

	// Returns the vertex at vertices[i].
	std::shared_ptr<Vertex<T> > getVertex(int i);
	// Returns the vertex by its data
	std::shared_ptr<Vertex<T> > getVertex(const T data);

	void addVertex(const std::shared_ptr<Vertex<T> > v);
	void addVertex(const T data);

	// Returns the length of vertices list.
	int verticesLength() const;
	void setupEdges();
	double getCost(int one, int two);

};

#include "Graph.cpp"
#endif