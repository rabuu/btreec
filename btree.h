#ifndef BTREE_H_
#define BTREE_H_

#include "types.h"
#include "node.h"

typedef struct {
	const size_t order;
	BTreeNode *root;
} BTree;

BTree btree_create(size_t order);
void btree_insert(BTree *btree, BTreeKey key);
bool btree_contains_key(BTree *btree, BTreeKey key);
void btree_dump(BTree *btree);

#endif // BTREE_H_
