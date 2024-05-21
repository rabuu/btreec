CFLAGS=-Wall -g

btreec: main.o btree.o node.o
	$(CC) $(CFLAGS) -o btreec main.o btree.o node.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

btree.o: btree.c
	$(CC) $(CFLAGS) -c btree.c

node.o: node.c
	$(CC) $(CFLAGS) -c node.c

.PHONY: clean
clean:
	rm btreec main.o btree.o node.o
