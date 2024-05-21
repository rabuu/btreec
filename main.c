#include <stddef.h>

#include "btree.h"

int main(void) {
	BTree tree = btree_create(5);
	btree_dump(&tree);

	btree_insert(&tree, 5);
	btree_dump(&tree);

	btree_insert(&tree, 3);
	btree_dump(&tree);

	btree_insert(&tree, 6);
	btree_dump(&tree);

	btree_insert(&tree, 7);
	btree_dump(&tree);

	btree_insert(&tree, 2);
	btree_dump(&tree);

	btree_insert(&tree, 0);
	btree_dump(&tree);

	return 0;
}
