#include <stdlib.h>

#include "btree.h"

BTreeNode *create_node(BTreeNode *parent) {
	BTreeNode *new = (BTreeNode*) malloc(sizeof(BTreeNode));
	new->count = 0;
	new->parent = parent;

	return new;
}

BTree btree_create(size_t B) {
	BTreeNode *root = create_node(NULL);
	BTree tree = { .B = B, .root = root };
	return tree;
}