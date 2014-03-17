project3: main.o 
	g++ main.o -o project3
main.o: main.cpp
	g++ -c main.cpp
