#include <stdio.h>

#include "btree.h"
#include "types.h"

int main(void) {
	BTree tree = btree_create(7);
	btree_dump(&tree);

	btree_insert(&tree, 5);
	btree_dump(&tree);

	btree_insert(&tree, 3);
	btree_dump(&tree);

	btree_insert(&tree, 6);
	btree_dump(&tree);

	btree_insert(&tree, 7);
	btree_dump(&tree);

	btree_insert(&tree, 99);
	btree_dump(&tree);

	btree_insert(&tree, 1234);
	btree_dump(&tree);

	btree_insert(&tree, 4);
	btree_dump(&tree);

	btree_insert(&tree, 2);
	btree_dump(&tree);

	btree_insert(&tree, 0);
	btree_dump(&tree);

	const BTreeKey key = 1233;
	if (btree_contains_key(&tree, key)) {
		printf("BTree contains %lu.\n", key);
	} else {
		printf("BTree does not contain %lu.\n", key);
	}

	return 0;
}
