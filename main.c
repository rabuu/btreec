#include <stddef.h>

#include "btree.h"

int main(void) {
	BTree tree = btree_create(4);

	btree_insert_empty(&tree);
	btree_insert_empty(&tree);
	btree_insert_empty(&tree);
	btree_insert_empty(&tree);
	btree_insert_empty(&tree);

	btree_dump(&tree);

	return 0;
}
