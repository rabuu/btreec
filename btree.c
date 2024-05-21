#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "btree.h"

BTreeNode *create_empty_node(size_t order, BTreeNode *parent) {
	BTreeNode *new = (BTreeNode*) malloc(sizeof(BTreeNode));
	new->parent = parent;

	size_t *keys = malloc((order - 1) * sizeof(BTreeKey));
	BTreeNode **children = malloc(order * sizeof(BTreeNode*));

	new->key_count = 0;
	new->keys = keys;
	new->child_count = 0;
	new->children = children;

	return new;
}

void append_empty_node(size_t order, BTreeNode *parent) {
	assert(parent->child_count < order && "Parent node is already full");

	BTreeNode *child = create_empty_node(order, parent);

	parent->children[parent->child_count] = child;
	parent->child_count += 1;
}

void dump_node(BTreeNode *node) {
	if (node == NULL) {
		printf("(not existing)\n");
		return;
	}

	if (node->child_count == 0) {
		printf("LEAF(");
		for (size_t i = 0; i < node->key_count; ++i) {
			printf("%lu", node->keys[i]);
			if (i != node->key_count - 1) {
				printf(",");
			}
		}
		printf(");\n");
		return;
	}

	printf("NODE(");
	for (size_t i = 0; i < node->key_count; ++i) {
		printf("%lu", node->keys[i]);
		if (i != node->key_count - 1) {
			printf(",");
		}
	}
	printf(") #%lu {\n", node->child_count);

	for (size_t i = 0; i < node->child_count; ++i) {
		dump_node(node->children[i]);
	}
	
	printf("}\n");
}


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
