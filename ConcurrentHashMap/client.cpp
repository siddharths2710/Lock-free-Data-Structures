#include <iostream>
#include <thread>
#include "conhashmap.h"

using namespace std;

#define NUM_THREADS 2
#define NO_ELE 10000

void push_even(ConHashMap* h)
{
	for (int i = 0; i < NO_ELE; i += 2) {
		// s->push(i);
		h->put(i * i, i);
	}
}

void push_odd(ConHashMap* h)
{
	for (int i = 1; i < NO_ELE; i += 2) {
		// s->push(i);
		h->put(i * i, i);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	ConHashMap* s = new ConHashMap();

	thread odd_thread(push_odd, s);
	thread even_thread(push_even, s);
	
	odd_thread.join();
	even_thread.join();
	
	// cout << (*s);
	// cout << endl;

	return 0;
}
