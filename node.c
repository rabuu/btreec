#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "node.h"

BTreeNode *create_empty_node(size_t order, BTreeNode *parent) {
	BTreeNode *new = (BTreeNode*) malloc(sizeof(BTreeNode));
	new->parent = parent;

	size_t *keys = malloc((order - 1) * sizeof(BTreeKey));
	BTreeNode **children = malloc(order * sizeof(BTreeNode*));

	new->key_count = 0;
	new->keys = keys;
	new->child_count = 0;
	new->children = children;

	return new;
}

void append_empty_node(size_t order, BTreeNode *parent) {
	assert(parent->child_count < order && "Parent node is already full");

	BTreeNode *child = create_empty_node(order, parent);

	parent->children[parent->child_count] = child;
	parent->child_count += 1;
}

void dump_node(BTreeNode *node, size_t depth) {
	char prefix[depth+1];
	for (int i = 0; i < depth; ++i) {
		prefix[i] = ' ';
	}
	prefix[depth] = '\0';

	if (node == NULL) {
		printf("%s(not existing)\n", prefix);
		return;
	}

	if (node->child_count == 0) {
		printf("%sLEAF(", prefix);
		for (size_t i = 0; i < node->key_count; ++i) {
			printf("%lu", node->keys[i]);
			if (i != node->key_count - 1) {
				printf(",");
			}
		}
		printf(");\n");
		return;
	}

	printf("%sNODE(", prefix);
	for (size_t i = 0; i < node->key_count; ++i) {
		printf("%lu", node->keys[i]);
		if (i != node->key_count - 1) {
			printf(",");
		}
	}
	printf(") #%lu {\n", node->child_count);

	for (size_t i = 0; i < node->child_count; ++i) {
		dump_node(node->children[i], depth + 1);
	}
	
	printf("%s}\n", prefix);
}
