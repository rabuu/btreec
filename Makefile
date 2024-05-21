CFLAGS=-Wall -g

btreec: main.o btree.o node.o binary_search.o
	$(CC) $(CFLAGS) -o btreec main.o btree.o node.o binary_search.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

btree.o: btree.c
	$(CC) $(CFLAGS) -c btree.c

node.o: node.c
	$(CC) $(CFLAGS) -c node.c

binary_search.o: binary_search.c
	$(CC) $(CFLAGS) -c binary_search.c

.PHONY: clean
clean:
	rm btreec main.o btree.o node.o
