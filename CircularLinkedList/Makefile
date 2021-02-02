CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile:    main.out

main.out:   main.o  ItemType.o  CircularLinkedList.o
	$(CC)   $(LFLAGS)   -o  main.out    main.o  ItemType.o  CircularLinkedList.o

main.o: main.cpp    ItemType.o  CircularLinkedList.o
	$(CC)   $(CFLAGS)   main.cpp

ItemType.o: ItemType.cpp    ItemType.h
	$(CC)   $(CFLAGS)   ItemType.cpp

CircularLinkedList.o: CircularLinkedList.cpp    CircularLinkedList.h 
	$(CC)   $(CFLAGS)   CircularLinkedList.cpp

run: main.out
	./main.out  input.txt

clean:
	rm *.o
	rm *.out
