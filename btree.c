#include <stdio.h>
#include <assert.h>

#include "btree.h"
#include "node.h"

BTree btree_create(size_t order) {
	BTreeNode *root = create_empty_node(order, NULL);

	BTree tree = { order, root };
	return tree;
}

void btree_insert(BTree *btree, BTreeKey key) {
	assert(0 && "Not yet implemented");
}

void btree_dump(BTree *btree) {
	printf("BTree of order %lu:\n", btree->order);
	dump_node(btree->root);
}
