main: main.o linked_list.o
	g++ -o main main.o linked_list.o

main.o: main.cpp include/linked_list.h
	g++ -c main.cpp

linked_list.o: src/linked_list.cpp include/linked_list.h
	g++ -c src/linked_list.cpp

clean:
	rm -f main main.o linked_list.o
