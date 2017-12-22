#ifndef STACK
#define STACK

#include "node.h"

#include <string>
#include <iostream>
#include <pthread.h>

using namespace std;


class Stack
{
	private:
		Node* top;
	public:
		Stack();
		void push(Node* n);
		Node* pop();
		Node* peek();
		friend ostream& operator<<(ostream &obj,  Stack &s);
};

#endif