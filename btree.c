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
	if (node_is_leaf(btree->root) && btree->root->key_count < btree->order - 1) {
		add_key_to_node(btree->root, key);
	} else {
		printf("Root is full\n");
	}
}

void btree_dump(BTree *btree) {
	printf("[BTree of order %lu]\n", btree->order);
	dump_node(btree->root, 0);
	printf("--------------------\n");
}
