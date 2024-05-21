#ifndef BTREE_H_
#define BTREE_H_

#include <stddef.h>

typedef struct node {
	struct node *parent;

	size_t count;
	size_t *keys;
	struct node **children;
} BTreeNode;

typedef struct {
	size_t order;
	BTreeNode *root;
} BTree;


BTree btree_create(size_t);
void btree_insert_empty(BTree*);
void btree_dump(BTree*);

#endif // BTREE_H_
