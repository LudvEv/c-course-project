

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
 * Return pointer to the list
 */
pbin_tree init_tree(void);

/*
 * Deletes litreest and all the elements
 * Params: tree - pointer to the tree
 * Returns none
 */
void destroy_tree(pbin_tree tree);


/*
 * Find max node in tree
 * Params: tree - pointer to the tree
 * Return pointer to the list
 */
pbin_tree TreeMax(pbin_tree tree);


/*
 * Find min node in tree
 * Params: tree - pointer to the tree
 * Return pointer to the list
 */
pbin_tree TreeMax(pbin_tree tree);


int tree_insert(pbin_tree tree, int key, double value);



pbin_tree TreeSearchRec(pbin_tree tree, int key);

pbin_tree NodeRemove(pbin_tree tree, int key);

int BreadthWalk(pbin_tree r, int n);