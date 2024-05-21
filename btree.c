#include <stdio.h>
#include <assert.h>

#include "btree.h"
#include "node.h"

BTree btree_create(size_t order) {
	BTreeNode *root = create_empty_node(order, NULL);

	BTree tree = { order, root };
	return tree;
}

void insert_key_into_subtree(BTreeNode *node, BTreeKey key, size_t order) {
	if (node_is_leaf(node) && node->key_count < order - 1) {
		add_key_to_node(node, key);
		return;
	}

	if (node_is_leaf(node)) {
		add_key_to_node(node, key);
		const size_t mid = node->key_count / 2;

		BTreeNode *left = create_empty_node(order, node);
		for (size_t i = 0; i < mid; ++i) {
			insert_key_into_subtree(left, node->keys[i], order);
		}

		BTreeNode *right = create_empty_node(order, node);
		for (size_t i = mid + 1; i < node->key_count; ++i) {
			insert_key_into_subtree(right, node->keys[i], order);
		}

		node->keys[0] = node->keys[mid];
		node->key_count = 1;

		append_node(left, node, order);
		append_node(right, node, order);
	}



}

void btree_insert(BTree *btree, BTreeKey key) {
	insert_key_into_subtree(btree->root, key, btree->order);
}

void btree_dump(BTree *btree) {
	printf("[BTree of order %lu]\n", btree->order);
	dump_node(btree->root, 0);
	printf("--------------------\n");
}
