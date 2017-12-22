#ifndef LSTACK
#define LSTACK

#include "node.h"

#include <string>
#include <iostream>
#include <mutex>
#include <pthread.h>

using namespace std;
class LockedStack
{
	private:
		Node* top;
		mutex mtx;
	public:
		LockedStack();
		void push(int);
		int pop();
		int peek();
		friend ostream& operator<<(ostream &obj, LockedStack& s);
};

#endif