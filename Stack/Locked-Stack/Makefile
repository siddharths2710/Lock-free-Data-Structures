CC=g++
run: client.o locked_stack.o node.o
	$(CC) -std=c++11 -pthread -o run client.o locked_stack.o node.o
client.o: client.cpp locked_stack.h
	$(CC) -std=c++11 -c client.cpp 
locked_stack.o: locked_stack.cpp locked_stack.h
	$(CC) -std=c++11 -c locked_stack.cpp 
node.o: node.cpp node.h
	$(CC) -std=c++11 -c node.cpp
clean:
	rm -f *.o && rm -f run
