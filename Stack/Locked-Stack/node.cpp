#include "node.h"

// Node::Node(): data(0),next(nullptr){}

template<typename T>
Node<T>::Node(T d): data(d), next(nullptr) {}

template<typename T>
Node<T>::Node(T d, Node<T>* n): data(d), next(n) {}

template<typename T>
void Node<T>::set_data(T d)
{
	this->data = d;
}

template<typename T>
void Node<T>::set_next(Node<T>* n)
{
	this->next = n;
}

template<typename T>
T Node<T>::get_data()
{
	return this->data; 
}

template<typename T>
Node<T>* Node<T>::get_next()
{
	return this->next;
}
