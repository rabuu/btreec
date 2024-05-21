#ifndef BTREE_H_
#define BTREE_H_

#include <stddef.h>

typedef size_t BTreeKey;

typedef struct node {
	struct node *parent;

	size_t key_count;
	BTreeKey *keys;

	size_t child_count;
	struct node **children;
} BTreeNode;

typedef struct {
	size_t order;
	BTreeNode *root;
} BTree;


BTree btree_create(size_t);
void btree_insert(BTree*, BTreeKey);
void btree_dump(BTree*);

#endif // BTREE_H_
