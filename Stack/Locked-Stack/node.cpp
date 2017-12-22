#include "node.h"

// Node::Node(): data(0),next(nullptr){}

Node::Node(int d): data(d), next(nullptr) {}

Node::Node(int d, Node* n): data(d), next(n) {}

void Node::set_data(int d)
{
	this->data = d;
}

void Node::set_next(Node* n)
{
	this->next = n;
}

int Node::get_data()
{
	return this->data; 
}

Node* Node::get_next()
{
	return this->next;
}
