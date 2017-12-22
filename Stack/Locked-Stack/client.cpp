#include "stack.h"
#include <iostream>
#include <pthread.h>
#include <time.h> 

using namespace std;

#define NUM_THREADS 2
void* pushone(void *sp)
{
	Stack* s = (Stack*) sp;
	Node* a = new Node(1);
	cout << "Pushing 1\n";
	s->push(a);
	// pthread_exit(NULL);
	cout << "Pushed 1\n";
	return NULL;
}

void* pushtwo(void *sp)
{
	Stack* s = (Stack*) sp;
	Node* a = new Node(2);
	cout << "Pushing 2\n";
	s->push(a);
	// pthread_exit(NULL);
	cout << "Pushed 2\n";
	return NULL;
}

int main(int argc, char const *argv[])
{
	
	srand (time(NULL));

	Stack* s = new Stack();
	
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
	
	cout << (*s);
	cout << endl;

	return 0;
}
