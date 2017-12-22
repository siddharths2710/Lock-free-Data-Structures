#include "stack.h"
using namespace std;
#include <mutex>

mutex mtx;

Stack::Stack(): top(nullptr){

}

void Stack::push(Node *n)
{
	//mtx.lock();
	lock_guard<mutex> gu(mtx);

	if (this->top == nullptr)
		this->top = n;
	else {
		// this->top->setNext(n);
		n->setNext(top);
		this->top = n;
	}

	// mtx.unlock();
}


Node* Stack::pop()
{
	// mtx.lock();
	lock_guard<mutex> gu(mtx);

	if(this->top != nullptr)
	{
		Node* tmp = this->top;
		this->top = this->top->getNext();
		return tmp;
	}
	// mtx.unlock();
	return nullptr;
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
	while(cur != nullptr)
	{
		obj<< cur->getData() << "->";
		cur = cur->getNext();
	}

	obj << "NULL\n";
	return obj;
}
