

#pragma once

#define FALSE 0
#define TRUE 1

typedef struct _bin_tree *pbin_tree;

typedef struct _bin_tree
{
	int key;
	pbin_tree left, right;
} bin_tree;

pbin_tree init_tree(void);

void destroy_tree(pbin_tree tree);

void print_tree(pbin_tree tree);

int tree_insert(pbin_tree tree, int key, double value);

int tree_remove(pbin_tree tree, int key);