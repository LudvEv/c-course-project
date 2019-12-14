

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
pbin_tree initTree(void);

/*
 * Deletes tree and all the elements
 * Params: tree - pointer to the tree
 * Returns none
 */
void destroyTree(pbin_tree tree);

/*
 * Adds an item in the tree
 * Params: tree - pointer to the tree
 *         key - key of the item
 *		   value - value of the item
 * Returns: point to the node
 */
int treeInsert(pbin_tree tree, int key, double value);


/*
 * Deletes an item in the tree
 * Params: tree - pointer to the list
 *         value - deleted value
 * Returns: point to the node
 */
int treeRemove(pbin_tree tree, int key);

/*
 * walk deep
 * Params: list - pointer to the list
 * Returns: 0 if tree is not empty
 			-1 if tree is empty
 */
int dfs(pbin_tree tree);


/*
 * walk around
 * Params: list - pointer to the list
 * Returns: 0 if tree is not empty
 			-1 if tree is empty
 */
int wfs(pbin_tree tree);

/*
 * Params: list - pointer to the list
 * Returns: amount an elements
 */
int CountTree(pbin_tree p);