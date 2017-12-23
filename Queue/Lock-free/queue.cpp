#include "queue.h"
using namespace std;

mutex mtx;

Queue::Queue(){

	//Initialize to dummy node
	front = new Node();
	rear = front.load(memory_order_relaxed);
}

void Queue::enqueue(void *np)
{
	Node *n = (Node*)np;

	
	while(1)
	{
		Node * old_rear = this->rear.load(memory_order_relaxed);
		old_rear->setNext(n);
		if ( (this->rear).compare_exchange_weak( old_rear, n,memory_order_release,memory_order_relaxed) )
      		return;
	}	
}


Node* Queue::dequeue()
{
	while(1)
	{
		Node *front = this->front.load(memory_order_relaxed);
		if(front == NULL)
			return NULL;
		Node * new_front = front->getNext();
		if( (this->front).compare_exchange_weak( front, new_front,memory_order_release,memory_order_relaxed) )
			return front;
	}
}



Node* Queue::get_front()
{
	return this->front.load(memory_order_relaxed);
}


Node* Queue::get_rear()
{
	return this->rear.load(memory_order_relaxed);
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
