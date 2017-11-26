run: client.o stack.o node.o
	g++ -std=c++11  -mcx16 -lpthread -o run client.o stack.o node.o 
client.o: client.cpp stack.h
	g++ -std=c++11 -c -mcx16 -lpthread client.cpp 
stack.o: stack.cpp stack.h
	g++ -std=c++11 -mcx16 -lpthread -c stack.cpp 
node.o: node.cpp node.h
	g++ -std=c++11 -c -mcx16 -lpthread node.cpp
clean:
	rm -f *.o && rm -f run