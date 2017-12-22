#ifndef LSTACK
#define LSTACK

#include "node.h"

#include <string>
#include <iostream>
#include <mutex>
#include <pthread.h>

using namespace std;
template<typename T>
class LockedStack
{
	private:
		Node<T>* top;
		mutex mtx;
	public:
		LockedStack();
		void push(T);
		T& pop();
		T& peek();
		friend ostream& operator<<(ostream &obj, LockedStack<T> &s);
};

#endif