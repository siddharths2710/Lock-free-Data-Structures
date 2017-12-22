#include "locked_stack.h"
using namespace std;
#include <mutex>

LockedStack::LockedStack(): top(nullptr) {}

void LockedStack::push(int v)
{
	lock_guard<mutex> gu(mtx);
	Node* n = new Node(v);

	if (this->top == nullptr)
		this->top = n;
	else {
		n->set_next(top);
		this->top = n;
	}
}

int LockedStack::pop()
{
	// mtx.lock();
	lock_guard<mutex> gu(mtx);

	if(this->top != nullptr)
	{
		Node* tmp = this->top;
		this->top = this->top->get_next();
		return tmp->get_data();
	}
	// mtx.unlock();
	return -1;
}

int LockedStack::peek()
{
	// lock_guard<mutex> gu(mtx);
	if (top != nullptr)
		return top->get_data();
	return -1;
}

ostream& operator<<(ostream& obj, LockedStack& s)
{
	Node* cur = s.top;

	lock_guard<mutex> gu(s.mtx);
	while(cur != nullptr)
	{
		obj<< cur->get_data() << "->";
		cur = cur->get_next();
	}

	obj << "NULL\n";
	return obj;
}
