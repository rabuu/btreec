btreec: main.o btree.o
	cc -o btreec main.o btree.o

main.o: main.c
	cc -c main.c

btree.o: btree.c btree.h
	cc -c btree.c

.PHONY: clean
clean:
	rm btreec main.o btree.o
