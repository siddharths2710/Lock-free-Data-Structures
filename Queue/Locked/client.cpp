#include <iostream>
#include <thread>
#include "queue.h"

using namespace std;

#define NUM_THREADS 2
#define NO_ELE 1000000
//#define NO_ELE 4
void enqueue_even(Queue* q)
{
	for (int i = 0; i < NO_ELE; i += 2) {
		q->enqueue( new Node(i));
	}
}

void enqueue_odd(Queue* q)
{
	for (int i = 1; i < NO_ELE; i += 2) {
		q->enqueue( new Node(i));
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	Queue* q = new Queue();

	thread odd_thread(enqueue_odd, q);
	thread even_thread(enqueue_even, q);
	
	odd_thread.join();
	even_thread.join();
	
	//cout << (*q);
	cout << endl;

	return 0;
}
