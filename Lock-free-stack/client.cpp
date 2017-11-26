#include "stack.h"
#include <thread>

using namespace std;

int main(int argc, char const *argv[])
{
	

	Stack *s = new Stack();
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);

	//Push three nodes to stack using two threads.
	thread thread_1(&Stack::push,*s,a); 
    thread thread_2(&Stack::push,*s,b);

    thread_1.join();
    thread_2.join();
	
	cout<< *s;
	return 0;
}