

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
	tree->parent = NULL;
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


pbin_tree TreeMax(pbin_tree tree)
{
	pbin_tree p = tree;
	while (p->right)
		p = p->right;
	return p;
}

pbin_tree TreeMin(pbin_tree tree)
{
	pbin_tree p = tree;
	while (p->left)
		p = p->left;
	return p;
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
		temptree->parent = NULL;
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
	if (tree->key >= key)
		tree_insert(tree->left, key, value);
	
	return 0;
}

int tree_remove(pbin_tree tree, int key)
{
	if (tree->key == key)
	{

	}
	else if (tree->key > key)
	{
		tree_remove(tree->left, key);
	}
	else 
		tree_remove(tree->right, key);
	return NULL;
}







