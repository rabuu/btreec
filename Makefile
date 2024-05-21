CFLAGS=-Wall -g

btreec: main.o btree.o
	$(CC) $(CFLAGS) -o btreec main.o btree.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

btree.o: btree.c btree.h
	$(CC) $(CFLAGS) -c btree.c

.PHONY: clean
clean:
	rm btreec main.o btree.o
