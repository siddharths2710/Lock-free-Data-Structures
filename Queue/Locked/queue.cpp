#include "queue.h"
using namespace std;

mutex mtx;

Queue::Queue(){

	//Initialize to dummy node
	front = new Node();
	rear = front;
}

void Queue::enqueue(void *np)
{
    lock_guard<mutex> gu(mtx);
	Node *n = (Node*)np;

	
	rear->setNext(n);
	rear = n;
}


Node* Queue::dequeue()
{
	lock_guard<mutex> gu(mtx);

	if(front == NULL)
		return NULL;
	Node *tmp = front;
	front = front->getNext();
	return tmp;
}



Node* Queue::get_front()
{
	return this->front;
}


Node* Queue::get_rear()
{
	return this->rear;
}

ostream& operator<<(ostream &obj,  Queue &q)
{
	Node* cur = q.get_front();
	Node* rear = q.get_rear();

	while(cur != rear)
	{
		obj<< cur->getData() << "->";
		cur = cur->getNext();
	}

	obj<< cur->getData() <<"-> NULL\n";
	return obj;	
}
