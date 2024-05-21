#include <stddef.h>

#include "btree.h"

int main(void) {
	BTree tree = btree_create(4);
	btree_dump(&tree);

	btree_insert(&tree, 0);
	btree_insert(&tree, 0);
	btree_insert(&tree, 0);

	btree_dump(&tree);

	return 0;
}
