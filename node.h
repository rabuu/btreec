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

BTreeNode *create_empty_node(BTreeNode *parent, size_t order);
void append_node(BTreeNode *child, BTreeNode *parent, size_t order);
void append_empty_node(BTreeNode *parent, size_t order);
bool node_is_leaf(BTreeNode *node);
void add_key_to_node(BTreeNode *node, BTreeKey key);
void dump_node(BTreeNode *node, size_t depth);

#endif // NODE_H_
