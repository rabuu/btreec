#include <stdio.h>
#include <assert.h>

#include "btree.h"
#include "node.h"
#include "binary_search.h"

BTree btree_create(size_t order) {
	BTreeNode *root = create_empty_node(NULL, order);

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

		BTreeNode *left = create_empty_node(node, order);
		for (size_t i = 0; i < mid; ++i) {
			insert_key_into_subtree(left, node->keys[i], order);
		}

		BTreeNode *right = create_empty_node(node, order);
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

bool subtree_contains_key(BTreeNode *node, BTreeKey key) {
	if (node->key_count == 0) {
		return false;
	}

	size_t index = search_key_index(node->keys, key, 0, node->key_count - 1);

	if (node->keys[index] == key) {
		return true;
	}

	if (index < node->child_count) {
		return subtree_contains_key(node->children[index], key);
	}

	return false;
}

bool btree_contains_key(BTree *btree, BTreeKey key) {
	return subtree_contains_key(btree->root, key);
}

void btree_dump(BTree *btree) {
	printf("[BTree of order %lu]\n", btree->order);
	dump_node(btree->root, 0);
	printf("--------------------\n");
}
