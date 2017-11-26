#include "stack.h"
using namespace std;

mutex mtx;

Stack::Stack():top(NULL){

}

void Stack::push(Node *n)
{
	while(1)
	{
		Node * old_top = this->top;
		n->setNext(old_top);
		if ( atomic_compare_exchange_weak( (atomic<Node>*)this->top, old_top, *n) )
      		return;
	}	
}

Node* Stack::pop_lockfree()
{
	while(1)
	{
		Node *top = this->top;
		if(top == NULL)
			return NULL;
		Node * new_top = top->getNext();
		if( atomic_compare_exchange_weak( (atomic<Node>*)this->top, top, *new_top) )
			return this->top;
	}
}

Node* Stack::pop_lock()
{
	mtx.lock();

	Node *top = this->top;
	if(top == NULL)
		return NULL;
	top = top->getNext();
	
	mtx.unlock();
	
	return top;
}

Node* Stack::get_top()
{
	return this->top;
}

ostream& operator<<(ostream &obj,  Stack &s)
{
	Node* cur = s.get_top();

	while(cur != NULL)
	{
		obj<< cur->getData() << "->";
		cur = cur->getNext();
	}

	obj<<"NULL\n";
	return obj;
}