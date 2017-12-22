#include "locked_stack.h"
using namespace std;
#include <mutex>

template<typename T>
LockedStack<T>::LockedStack(): top(nullptr) {}

template<typename T>
void LockedStack<T>::push(T v)
{
	lock_guard<mutex> gu(mtx);
	Node<T>* n = new Node<T>(v);

	if (this->top == nullptr)
		this->top = n;
	else {
		n->setNext(top);
		this->top = n;
	}
}

template<typename T>
T& LockedStack<T>::pop()
{
	// mtx.lock();
	lock_guard<mutex> gu(mtx);

	if(this->top != nullptr)
	{
		Node<T>* tmp = this->top;
		this->top = this->top->getNext();
		return tmp->data;
	}
	// mtx.unlock();
	return nullptr;
}

template<typename T>
T& LockedStack<T>::peek()
{
	// lock_guard<mutex> gu(mtx);
	if (top != nullptr)
		return top->data;
	return nullptr;
}

template<typename T>
ostream& operator<<(ostream& obj, LockedStack<T>& s)
{
	Node<T>* cur = s.top;

	lock_guard<mutex> gu(s.mtx);
	while(cur != nullptr)
	{
		obj<< cur->getData() << "->";
		cur = cur->getNext();
	}

	obj << "NULL\n";
	return obj;
}
