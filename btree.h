#ifndef BTREE_H_
#define BTREE_H_

#include <stddef.h>
#include <stdint.h>

typedef struct node {
	struct node *parent;

	size_t count;
	int32_t *values;
	struct node **children;
} BTreeNode;

typedef struct {
	size_t B;
	BTreeNode *root;
} BTree;


BTree btree_create(size_t);

#endif // BTREE_H_
