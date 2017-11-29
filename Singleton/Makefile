run: singleton.o main.o
	g++ -std=c++11 -mcx16 -lpthread -o run main.o singleton.o -g
singleton.o: singleton.cpp singleton.h
	g++ -std=c++11 -mcx16 -lpthread -c singleton.cpp -g
main.o: main.cpp singleton.h
	g++ -std=c++11 -c -mcx16 -lpthread main.cpp -g
clean:
	rm -f *.o && rm -f run
