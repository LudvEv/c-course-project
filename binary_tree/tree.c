

#include "tree.h"
#include <stdlib.h>



pbin_tree init_tree(void)
{
	pbin_tree tree = malloc(sizeof(bin_tree));
	if (tree == NULL)
		return	NULL;
	tree->key = 0;
	tree->value = 0;
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


pbin_tree TreeSearchRec(pbin_tree tree, int key)
{ 
	if(!tree||key==tree->key)
		return tree;
	if(key < tree->key)
		return TreeSearchRec(tree->left, key); 
	else 
		return TreeSearchRec(tree->right, key);
}

pbin_tree TreeJointLeft(pbin_tree a, pbin_tree b) 
{ 
	pbin_tree p;
	if(!a) 
		return b; 
	if(!b) 
		return a; 
	p=TreeMax(a);
	if(!(p->key < b->key) ) 
		return 0; 
	p->parent = NULL;
	p->left=a; 
	p->right=b;
	return p;
}

pbin_tree NodeRemove(pbin_tree tree, int key)
{ 
	pbin_tree p, q, a, b;

	p=TreeSearchRec(tree, key);
	a=p->left;
	b=p->right;
	q=TreeJointLeft(a, b); // q=TreeJointRight(a, b); 
	p->parent=q;
	return q;
}

int tree_insert(pbin_tree tree, int key, double value)
{
	if (tree == NULL)
	{
		pbin_tree temptree = (pbin_tree)malloc(sizeof(bin_tree));
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
	if (tree->key == 0)
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


int BreadthWalk(pbin_tree r, int n)
{ 
	pbin_tree p = r, s; 
	int i=-1;
	int head=0,tail=0;
	if(!p) 
		return i; 
	s=(pbin_tree)malloc(sizeof(pbin_tree)*n); 
	s[tail++]=p;
	while(head!=tail)
	{ 
		p=s[head++];
		printf("%d", p->key);
		if(p->left) 
			s[tail++]=p->left;
		if(p->right) 
			s[tail++]=p->right;
	} // while return i;
}






