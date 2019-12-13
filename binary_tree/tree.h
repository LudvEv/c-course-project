

#pragma once

#define FALSE 0
#define TRUE 1

typedef struct _bin_tree *pbin_tree;

typedef struct _bin_tree
{
	int key;
	double value;
	pbin_tree parent, left, right;
} bin_tree;

/*
 * Creates an empty tree
 * Params: none
 * Return pointer to the tree
 */
pbin_tree init_tree(void);

/*
 * Deletes litreest and all the elements
 * Params: tree - pointer to the tree
 * Returns none
 */
pbin_tree destroy_tree(pbin_tree tree);



/*
 * Adds an item in the tree
 * Params: tree - pointer to the tree
 *         key - key of the item
 *		   value - value of the item
 * Returns: point to the updated tree
 */
pbin_tree tree_insert(pbin_tree tree, int key, double value);


/*
 * Deletes a tree element 
 * Params: list - pointer to the list
 *         value - deleted value
 * Returns: point to the updated tree
 */



int dfs(pbin_tree tree);

int wfs(pbin_tree tree);
