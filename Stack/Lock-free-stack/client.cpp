#include <iostream>
#include <thread>
#include "lockless_stack.h"

using namespace std;

#define NUM_THREADS 2
#define NO_ELE 1000000

void push_even(Stack* s)
{
	for (int i = 0; i < NO_ELE; i += 2) {
		s->push(i);
	}
}

void push_odd(Stack* s)
{
	for (int i = 1; i < NO_ELE; i += 2) {
		s->push(i);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	Stack* s = new Stack();

	thread odd_thread(push_odd, s);
	thread even_thread(push_even, s);
	
	odd_thread.join();
	even_thread.join();
	
	// cout << (*s);
	cout << endl;

	return 0;
}
