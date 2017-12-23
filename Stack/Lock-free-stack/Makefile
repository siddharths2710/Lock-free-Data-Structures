CC=g++-5
run: client.o lockless_stack.o node.o
	$(CC) -std=c++11 -pthread -o run client.o lockless_stack.o node.o
client.o: client.cpp lockless_stack.h
	$(CC) -std=c++11 -c client.cpp 
lockless_stack.o: lockless_stack.cpp lockless_stack.h
	$(CC) -std=c++11 -c lockless_stack.cpp 
node.o: node.cpp node.h
	$(CC) -std=c++11 -c node.cpp
clean:
	rm -f *.o && rm -f run
