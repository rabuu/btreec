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
void append_node(BTreeNode *child, BTreeNode *parent, size_t order);
void append_empty_node(BTreeNode *parent, size_t order);
bool node_is_leaf(BTreeNode*);
void add_key_to_node(BTreeNode*, BTreeKey);
void dump_node(BTreeNode*, size_t depth);

#endif // NODE_H_
