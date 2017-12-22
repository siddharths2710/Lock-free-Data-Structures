run: client.o locked_stack.o node.o
	g++ -std=c++11    -o run client.o locked_stack.o node.o -lpthread 
client.o: client.cpp locked_stack.h
	g++ -std=c++11 -c  -lpthread client.cpp 
locked_stack.o: locked_stack.cpp locked_stack.h
	g++ -std=c++11  -lpthread -c locked_stack.cpp 
node.o: node.cpp node.h
	g++ -std=c++11 -c  -lpthread node.cpp
clean:
	rm -f *.o && rm -f run