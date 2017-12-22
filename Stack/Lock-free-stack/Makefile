# run: client.o stack.o node.o
# 	g++ -std=c++11    -o run client.o stack.o node.o -lpthread 
# client.o: client.cpp stack.h
# 	g++ -std=c++11 -c  -lpthread client.cpp 
# stack.o: stack.cpp stack.h
# 	g++ -std=c++11  -lpthread -c stack.cpp 
# node.o: node.cpp node.h
# 	g++ -std=c++11 -c  -lpthread node.cpp
# clean:
# 	rm -f *.o && rm -f run

CC=clang++
run: client.o lockless_stack.o node.o
	$(CC) -std=c++11 -o run client.o lockless_stack.o node.o
client.o: client.cpp lockless_stack.h
	$(CC) -std=c++11 -c client.cpp 
lockless_stack.o: lockless_stack.cpp lockless_stack.h
	$(CC) -std=c++11 -c lockless_stack.cpp 
node.o: node.cpp node.h
	$(CC) -std=c++11 -c node.cpp
clean:
	rm -f *.o && rm -f run
