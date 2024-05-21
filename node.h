#ifndef NODE_H_
#define NODE_H_

#include "types.h"

typedef struct node {
	struct node *parent;

	size_t key_count;
	BTreeKey *keys;

	size_t child_count;
	struct node **children;
} BTreeNode;

BTreeNode *create_empty_node(size_t order, BTreeNode *parent);
void dump_node(BTreeNode*);

#endif // NODE_H_
