

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>



pbin_tree init_tree(void)
{
	pbin_tree tree = (pbin_tree)malloc(sizeof(bin_tree));
	if (tree == NULL)
		return	NULL;
	tree->key = 0;
	tree->value = 0;
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;
	return tree;
}

pbin_tree destroy_tree(pbin_tree tree)
{
    if(!tree)
        return NULL;
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    free(tree);
    return tree;
}


pbin_tree tree_insert(pbin_tree tree, int key, double value)
{
    if(tree->key == NULL)
    {
        tree->key = key;
        tree->value = value;
        tree->parent = NULL;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    } // if
    pbin_tree q = tree, p;
    pbin_tree node = init_tree();
    if (!node)
        return -1;
    node->key = key;
    node->value = value;
    while(q)
    {
        p=q;
        if(node->key < p->key)
        {
            q=p->left;
            if(!q)
            {
                p->left=node;
                node->parent=p;
            }
            
        }// if
        else
        {
            q=p->right;
            if(!q)
            {
                p->right=node;
                node->parent=p;
                
            }
        }// else
    } //while
    return p;
}

int max_value(int a, int b)
{
	if (a >= b)
		return a;
	else 
		return b;
}

int number_of_level(pbin_tree tree, int level)
{
	pbin_tree p = tree;
	if (!p)
		return level;
	level = max_value(number_of_level(p->left, level + 1), number_of_level(p->right, level + 1));
	return level;
}

void myprocessng(pbin_tree tree)
{
    printf("%d = %.2f\n", tree->key, tree->value);
}


int dfs(pbin_tree tree)
{
    pbin_tree p = tree;
    if (!tree)
        return -1;
    printf("%d %.1f \n", p->key, p->value);
    dfs(p->left);
    dfs(p->right);
    return 0;
}

int wfs(pbin_tree r)
{
    int n = CountTree(r);
    pbin_tree p=r,s;
    int i=-1;
    int head=0, tail=0;
    if(!p)
        return i;
    s=(pbin_tree)malloc(sizeof(pbin_tree)*n);
    s[tail++] = *p;
    while(head!=tail)
    {
        p = &(s[head++]);
        myprocessng(p);
        if(p->left)
            s[tail++]=*(p->left);
        if(p->right)
            s[tail++]=*(p->right);
    } // while
    return i;
}

int CountTree(pbin_tree p) {
    if(!p)
        return 0;
    return CountTree(p->left)+CountTree(p->right)+1;
}


