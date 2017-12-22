run: client.o stack.o node.o
	g++ -std=c++11    -o run client.o stack.o node.o -lpthread 
client.o: client.cpp stack.h
	g++ -std=c++11 -c  -lpthread client.cpp 
stack.o: stack.cpp stack.h
	g++ -std=c++11  -lpthread -c stack.cpp 
node.o: node.cpp node.h
	g++ -std=c++11 -c  -lpthread node.cpp
clean:
	rm -f *.o && rm -f run