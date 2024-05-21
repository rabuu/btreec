#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "node.h"
#include "binary_search.h"

BTreeNode *create_empty_node(BTreeNode *parent, size_t order) {
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

bool node_is_leaf(BTreeNode *node) {
	return node->child_count == 0;
}

void append_node(BTreeNode *child, BTreeNode *parent, size_t order) {
	assert(parent->child_count < order && "Parent node is already full");
	parent->children[parent->child_count] = child;
	parent->child_count += 1;
}

void append_empty_node(BTreeNode *parent, size_t order) {
	assert(parent->child_count < order && "Parent node is already full");

	BTreeNode *child = create_empty_node(parent, order);
	append_node(child, parent, order);
}

void add_key_to_node(BTreeNode *node, BTreeKey key) {
	if (node->key_count == 0) {
		node->keys[0] = key;
		node->key_count++;
		return;
	}

	size_t index = search_key_index(node->keys, key, 0, node->key_count - 1);
	if (key == node->keys[index]) {
		printf("Key %lu does already exist\n", key);
		return;
	}

	for (size_t i = node->key_count; i > index; --i) {
		node->keys[i] = node->keys[i-1];
	}
	node->keys[index] = key;

	node->key_count++;
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
