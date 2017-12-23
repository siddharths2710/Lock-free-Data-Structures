run: client.o queue.o node.o
	g++ -std=c++11    -o run client.o queue.o node.o -lpthread 
client.o: client.cpp queue.h
	g++ -std=c++11 -c  -lpthread client.cpp 
queue.o: queue.cpp queue.h
	g++ -std=c++11  -lpthread -c queue.cpp 
node.o: node.cpp node.h
	g++ -std=c++11 -c  -lpthread node.cpp
clean:
	rm -f *.o && rm -f run