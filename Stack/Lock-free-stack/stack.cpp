#include "stack.h"
using namespace std;

mutex mtx;

Stack::Stack():top(NULL){

}

void Stack::push(void *np)
{
	Node *n = (Node*)np;
	while(1)
	{
		Node * old_top = this->top.load(memory_order_relaxed);
		n->setNext(old_top);
		if ( (this->top).compare_exchange_weak( old_top, n,memory_order_release,memory_order_relaxed) )
      		return;
	}	
}


Node* Stack::pop_lockfree()
{
	while(1)
	{
		Node *top = this->top.load(memory_order_relaxed);
		if(top == NULL)
			return NULL;
		Node * new_top = top->getNext();
		if( (this->top).compare_exchange_weak( top, new_top,memory_order_release,memory_order_relaxed) )
			return this->top.load(memory_order_relaxed);
	}
}

Node* Stack::pop_lock()
{
	mtx.lock();

	Node *top = this->top.load(memory_order_relaxed);
	if(top == NULL)
		return NULL;
	top = top->getNext();
	
	mtx.unlock();
	
	return top;
}

Node* Stack::get_top()
{
	return this->top.load(memory_order_relaxed);
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