

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>



pbin_tree initTree(void)
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

void destroyTree(pbin_tree tree)
{
    if (!tree)
        return;
    destroyTree(tree->left);
    destroyTree(tree->right);
    free(tree);

}


int treeInsert(pbin_tree tree, int key, double value)
{
    if(tree->key == NULL)
    {
        tree->key = key;
        tree->value = value;
        tree->parent = NULL;
        tree->left = NULL;
        tree->right = NULL;
        return 1;
    } // if
    pbin_tree q = tree, p;
    pbin_tree node = initTree();
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
        else if(node->key > p->key)
        {
            q=p->right;
            if(!q)
            {
                p->right=node;
                node->parent=p;
                
            }
        }// else
        else
        {
            p->value = node->value;
            return 1;
        }
    } //while
    return 1;
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

int CountTree(pbin_tree p) 
{
    if (!p)
        return 0;
    return CountTree(p->left) + CountTree(p->right)+1;
}

int wfs(pbin_tree tree)
{
    int n = CountTree(tree);
    pbin_tree p = tree, s;
    int i = -1;
    int head = 0, tail = 0;
    if (!p)
        return i;
    s = (pbin_tree)malloc(sizeof(bin_tree) * n);
    s[tail++] = *p;
    while (head!=tail)
    {
        p = &(s[head++]);
        myprocessng(p);
        if (p->left)
            s[tail++] = *(p->left);
        if (p->right)
            s[tail++] = *(p->right);
    } // while
    free(s);
    return i;
}



pbin_tree TreeMin(pbin_tree tree)
{
    pbin_tree p = tree;
    while (p->left)
        p = p->left;
    return p;
}

pbin_tree TreeMax(pbin_tree tree)
{
    pbin_tree p = tree;
    while (p->right)
        p = p->right;
    return p;
}

pbin_tree TreeJointLeft(pbin_tree a, pbin_tree b) {
    pbin_tree p;
    if (!a)
        return b;
    if (!b)
        return a;
    p = TreeMax(a);
    
    if (!(p->key < b->key))
        return 0;
    p->parent->right = 0;
    p->parent = 0;
    p->left = a;
    p->right = b;
    return p;
}

pbin_tree TreeSearchIter(pbin_tree tree, int key)
{
    pbin_tree p;
    for (p=tree; !p || key != p->key;)
    {
        if (key < tree->key)
            p = p->left;
        else
            p = p->right;
    } //for
    return p;
}

int treeRemove(pbin_tree tree, int key)
{
    pbin_tree p, q, a, b;
    if (!tree)
        return 0;
    p = TreeSearchIter(tree, key);
    a = p->left;
    b = p->right;
    q = TreeJointLeft(a, b);
    if (p->parent->left == p)
    {
        p->parent->left = q;
    }
    else if (p->parent->right == p)
    {
        p->parent->right = q;
    }
    else
        return 0;
    free(p);
    return 0;
}


