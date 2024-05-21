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
	size_t order;
	BTreeNode *root;
} BTree;


BTree btree_create(size_t);
void btree_insert_empty(BTree*);
void btree_dump(BTree*);

#endif // BTREE_H_
