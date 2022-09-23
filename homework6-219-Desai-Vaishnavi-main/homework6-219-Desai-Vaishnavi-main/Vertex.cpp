#ifndef VERTEX_CPP
#define VERTEX_CPP

#include "Vertex.h"

template<class T>
Vertex<T>::Vertex(T data)
{ 
	setValue(data);
}

template<class T>
void Vertex<T>::addEdge(std::shared_ptr<Edge<T> >newEdge) { edges.add(newEdge); }

template<class T>
void Vertex<T>::clearEdges() { edges.clear(); }

template<class T>
void Vertex<T>::setValue(T data) { m_value = data; }

template<class T>
T Vertex<T>::getValue() const { return m_value; }

template<class T>
int Vertex<T>::getEdgeCount() const { return edges.size(); }

template<class T >
std::shared_ptr<Edge<T> > Vertex<T>::getEdge(int i) const { return edges[i]; }

template<class T>
bool Vertex<T>::connectedTo(const T value) {
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i]->getDest()->m_value == value) return true;
	}
	return false;
}

#endif