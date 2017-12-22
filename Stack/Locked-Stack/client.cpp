#include "locked_stack.h"
#include <iostream>
#include <thread>

using namespace std;

#define NUM_THREADS 2
//#define NO_ELE 1000000
#define NO_ELE 10
void push_odd(LockedStack* s)
{
	for (int i = 1; i < NO_ELE; i += 2) {
		s->push(i);
	}
}

void push_even(LockedStack* s)
{
	for (int i = 2; i < NO_ELE; i += 2) {
		s->push(i);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	LockedStack* s = new LockedStack();
	
	thread odd_thread(push_odd, s);
	thread even_thread(push_even, s);
	
	odd_thread.join();
	even_thread.join();
	
	 cout << (*s);
	cout << endl;

	return 0;
}
