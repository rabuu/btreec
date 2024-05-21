#ifndef BTREE_H_
#define BTREE_H_

#include "types.h"
#include "node.h"

typedef struct {
	size_t order;
	BTreeNode *root;
} BTree;

BTree btree_create(size_t);
void btree_insert(BTree*, BTreeKey);
void btree_dump(BTree*);

#endif // BTREE_H_
