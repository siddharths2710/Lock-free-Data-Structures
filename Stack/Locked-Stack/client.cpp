#include "locked_stack.h"
#include <iostream>
#include <pthread.h>
#include <time.h> 

using namespace std;

#define NUM_THREADS 2
#define NO_ELE 1000000
void* pushone(void *sp)
{
	LockedStack<int>* s = (LockedStack<int>*) sp;
	for (int i = 1; i < NO_ELE; i += 2) {
		// Node<int>* a = new Node<int>(i);
		// cout << "Pushing 1\n";
		s->push(i);
		// cout << "Pushed 1\n";
	}
	// pthread_exit(NULL);
	return NULL;
}

void* pushtwo(void *sp)
{
	LockedStack<int>* s = (LockedStack<int>*) sp;
	for (int i = 2; i < NO_ELE; i += 2) {
		// Node<int>* a = new Node<int>(i);
		// cout << "Pushing 1\n";
		s->push(i);
		// cout << "Pushed 1\n";
	}
	// pthread_exit(NULL);
	return NULL;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	LockedStack<int>* s = new LockedStack<int>();
	
	pthread_t threads[NUM_THREADS];
	// Node *a = new Node(1);
	// Node *b = new Node(2);
	// Node *c = new Node(3);

	//s->push(c);
	//s->push(b);
	//s->push(a);

   	pthread_create(&threads[0], NULL, pushone, s);
   	pthread_create(&threads[1], NULL, pushtwo, s);
	
   	// cout << "Started\n";

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	// cout << "Joined\n";
	
	// cout << (*s);
	cout << endl;

	return 0;
}
