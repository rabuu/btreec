#include <stdio.h>
#include <stddef.h>

#include "btree.h"

int main(void) {
	BTree tree = btree_create(4);

	printf("Hello, world!\n");
	return 0;
}
