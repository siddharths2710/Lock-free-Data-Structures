#include <iostream>
#include <thread>
#include <map>
// #include "conhashmap.h"

using namespace std;

#define NUM_THREADS 2
#define NO_ELE 1000

void push_even(map<int, int>* h)
{
	for (int i = 0; i < NO_ELE; i += 2) {
		// s->push(i);
		h->insert(make_pair(i*i, i));
		// h[i*i] = i;
	}
}

void push_odd(map<int, int>* h)
{
	for (int i = 1; i < NO_ELE; i += 2) {
		// s->push(i);
		h->insert(make_pair(i*i, i));
		// h->insert_or_assign(i*i, i);
		// h[i*i] = i;
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	// ConHashMap* s = new ConHashMap();
	map<int, int>* h = new map<int, int>();
	cout << h->size() << endl;

	thread odd_thread(push_odd, h);
	thread even_thread(push_even, h);
	
	odd_thread.join();
	even_thread.join();
	
	// cout << (*s);
	// cout << h << endl;
	// cout << h->size() << endl;

	return 0;
}
