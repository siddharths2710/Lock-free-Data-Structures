#include "stack.h"
using namespace std;
#include <mutex>

mutex mtx;

Stack::Stack():top(NULL){

}

void Stack::push(Node *n)
{
	//mtx.lock();
	lock_guard<mutex> gu(mtx);

	if (this->top == NULL)
		this->top = n;
	else {
		this->top->setNext(n);
		this->top = n;
	}

	// mtx.unlock();	
}


Node* Stack::pop()
{
	// mtx.lock();
	lock_guard<mutex> gu(mtx);

	if(this->top != NULL)
	{
		this->top = this->top->getNext();
	}

	// mtx.unlock();
	
	return top;
}

Node* Stack::peek()
{
	lock_guard<mutex> gu(mtx);
	return this->top;
}

ostream& operator<<(ostream &obj,  Stack &s)
{
	Node* cur = s.peek();

	lock_guard<mutex> gu(mtx);
	while(cur != NULL)
	{
		obj<< cur->getData() << "->";
		cur = cur->getNext();
	}

	obj << "NULL\n";
	return obj;	
}
