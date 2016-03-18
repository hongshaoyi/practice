main: main.o linked_list.o
	gcc -o main main.o linked_list.o

main.o: main.cpp, linked_list.h
	gcc -c main.cpp

linked_list.o: linked_list.h linked_list.cpp
	gcc -c include/linked_list.h src/linked_list.cpp
