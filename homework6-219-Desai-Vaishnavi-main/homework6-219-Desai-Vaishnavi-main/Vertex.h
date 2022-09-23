#ifndef VERTEX_H
#define VERTEX_H

#include <memory>

#include "LinkedList.h"
#include "Edge.h"

template <class T> class Edge;

template <class T>
class Vertex
{
public:
	Vertex(T data);

	void addEdge(std::shared_ptr<Edge<T> > newEdge);
	void clearEdges();

	void setValue(T data);

	T getValue() const;
	int getEdgeCount() const;
	std::shared_ptr<Edge<T> > getEdge(int i) const;
	bool connectedTo(const T value);

private:
	T m_value;
	LinkedList<std::shared_ptr<Edge<T> > > edges;
};

#include "Vertex.cpp"
#endif