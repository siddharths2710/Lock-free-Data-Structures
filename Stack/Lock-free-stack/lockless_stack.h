#ifndef LCSTACK
#define LCSTACK

#include "node.h"
#include <iostream>
#include <atomic>

using namespace std;
class Stack
{
	private:
		atomic<Node *> top;
	public:
		Stack();
		void push(int v);
		Node* pop();
		Node* get_top();
		friend ostream& operator<<(ostream &obj,  Stack &s);
};

#endif