CC=clang++
# run: conhashmap.o client.o
# 	$(CC) -std=c++11 -o run client.o conhashmap.o
# conhashmap.o: conhashmap.cpp conhashmap.h
# 	$(CC) -std=c++11 -c conhashmap.cpp
# client.o: client.cpp conhashmap.h
# 	$(CC) -std=c++11 -c client.cpp
# clean:
# 	rm -f *.o && rm -f run

# CC=g++-5
run: client.o conhashmap.o node.o
	$(CC) -std=c++11 -pthread -o run client.o conhashmap.o node.o -g
client.o: client.cpp conhashmap.h
	$(CC) -std=c++11 -c client.cpp -g
conhashmap.o: conhashmap.cpp conhashmap.h
	$(CC) -std=c++11 -c conhashmap.cpp -g
node.o: node.cpp node.h
	$(CC) -std=c++11 -c node.cpp -g
clean:
	rm -f *.o && rm -f run
