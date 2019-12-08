#include <stdio.h>
#include "tree.h"


int main(int argc, char const *argv[])
{
	pbin_tree tree;
	tree = init_tree();
	int a;
	a = tree_insert(tree, 2, 1);
	a = BreadthWalk(tree, 1);
	return 0;
}