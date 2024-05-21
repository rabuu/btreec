#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "btree.h"

BTreeNode *create_empty_node(size_t order, BTreeNode *parent) {
	BTreeNode *new = (BTreeNode*) malloc(sizeof(BTreeNode));
	new->parent = parent;

	BTreeNode **children = calloc(order, sizeof(BTreeNode*));
	new->count = 0;
	new->children = children;

	return new;
}

void append_empty_node(size_t order, BTreeNode *parent) {
	assert(parent->count < order && "Parent node is already full");

	BTreeNode *child = create_empty_node(order, parent);

	parent->children[parent->count] = child;
	parent->count += 1;
}

void dump_node(BTreeNode *node) {
	if (node == NULL) {
		printf("(not existing)\n");
		return;
	}

	if (node->count == 0) {
		printf("NODE\n");
		return;
	}

	printf("NODE(%lu) {\n", node->count);

	for (size_t i = 0; i < node->count; i++) {
		dump_node(node->children[i]);
	}
	
	printf("}\n");
}


BTree btree_create(size_t order) {
	BTreeNode *root = create_empty_node(order, NULL);

	BTree tree = { order, root };
	return tree;
}

void btree_insert_empty(BTree *btree) {
	append_empty_node(btree->order, btree->root);
}

void btree_dump(BTree *btree) {
	printf("BTree of order %lu:\n", btree->order);
	dump_node(btree->root);
}
