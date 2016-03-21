main: main.o linked_list.o linked_list_unit_test.o
	g++ -g -o main main.o linked_list.o linked_list_unit_test.o

main.o: main.cpp include/linked_list.h
	g++ -g -c main.cpp

linked_list.o: src/linked_list.cpp include/linked_list.h
	g++ -g -c src/linked_list.cpp

linked_list_unit_test.o: unit_test/linked_list_unit_test.cpp unit_test/linked_list_unit_test.h
	g++ -g -c unit_test/linked_list_unit_test.cpp

clean:
	rm -f main main.o linked_list.o linked_list_unit_test.o
