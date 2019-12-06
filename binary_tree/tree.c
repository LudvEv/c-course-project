

#include "tree.h"
#include <stdlib.h>



pbin_tree init_tree(void)
{
	pbin_tree tree = malloc(sizeof(bin_tree));
	if (tree == NULL)
		return	NULL;
	tree->key = NULL;
	tree->value = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

void destroy_tree(pbin_tree tree)
{
	if (tree)
	{
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		free(tree);
	}
}



int tree_insert(pbin_tree tree, int key, double value)
{
	

	if (tree == NULL)
	{
		pbin_tree temptree = malloc(sizeof(struct bin_tree));
		if (!temptree)
			return -1;
		temptree->key = key;
		temptree->value = value;
		temptree->left = NULL;
		temptree->right = NULL;
		tree = temptree;
		return 0;
	}
	if (tree->key == NULL)
	{
		tree->key = key;
		tree->value = value;
		return 0;
	}
	if (tree->key < key)
		tree_insert(tree->right, key, value);
	if (tree->key > key)
		tree_insert(tree->left, key, value);
	if (tree->key == key)
	{
		printf("An item with this key already exists!");
		return 0;
	}
	return 0;
}

int tree_remove(pbin_tree tree, int key)
{
	return NULL;
}