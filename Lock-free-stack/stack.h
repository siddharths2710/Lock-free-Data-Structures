#ifndef STACK
#define STACK

#include "node.h"
#include <atomic>
#include <mutex>
#include <string>
#include <iostream>
#include <pthread.h>

using namespace std;
extern mutex mtx;
class Stack
{
	private:
		atomic<Node *> top;
	public:
		Stack();
		void push(void *n);	
		Node* pop_lockfree();
		Node* pop_lock();
		Node* get_top();
		friend ostream& operator<<(ostream &obj,  Stack &s);
};

#endif