#include "stack.h"
#include <pthread.h>
#include <time.h> 

using namespace std;

#define NUM_THREADS 2
void* pushone(void *sp)
{
	Node *a = new Node(1);
	Stack *s = (Stack*)sp;
	s->push(a);
	pthread_exit(NULL);
}


void* pushtwo(void *sp)
{
	Node *a = new Node(2);
	Stack *s = (Stack*)sp;
	s->push(a);
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	
	srand (time(NULL));

	Stack *s = new Stack();
	
	pthread_t threads[NUM_THREADS];
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);

	//s->push(c);
	//s->push(b);
	//s->push(a);

   

   	pthread_create(&threads[0],NULL,pushone,s);
   	pthread_create(&threads[1],NULL,pushtwo,s);
	
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);
	
	cout << (*s);
	cout << endl;

	return 0;
}