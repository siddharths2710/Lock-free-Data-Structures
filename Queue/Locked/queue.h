#ifndef Q
#define Q

#include "node.h"
#include <atomic>
#include <mutex>
#include <string>
#include <iostream>
#include <pthread.h>

using namespace std; 
class Queue
{
	private:
		Node* front;
		Node* rear;
		mutex mtx;
	public:
		Queue();
		void enqueue(void *n);	
		Node* dequeue();
		Node* get_front();
		Node* get_rear();
		friend ostream& operator<<(ostream &obj,  Queue &s);
};

#endif