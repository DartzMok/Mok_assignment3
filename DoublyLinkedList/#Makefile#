CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile:    main.out

main.out:   main.o 	ItemType.o	DoublyLinkedList.o
	$(CC)	$(LFLAGS)	-o  main.out	main.o	ItemType.o	DoublyLinkedList.o

main.o: main.cpp    ItemType.o  DoublyLinkedList.o
	$(CC)	$(CFLAGS)	main.cpp

ItemType.o: ItemType.cpp    ItemType.h
	$(CC)	$(CFLAGS)	ItemType.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp    DoublyLinkedList.h
	$(CC)	$(CFLAGS)	DoublyLinkedList.cpp

run: main.out
	./main.out	input.txt

clean:
	rm *.o
	rm *.out
