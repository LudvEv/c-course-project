#include <stdio.h>
#include "tree.h"


int main(void)
{
    pbin_tree tree = init_tree();
    tree_insert(tree, 5, 2);
    tree_insert(tree, 1, 2);
    tree_insert(tree, 3, 2);
    tree_insert(tree, 6, 2);
    printf("%d\n>>>>>>>\n", CountTree(tree));
    dfs(tree);
    printf(">>>>>>>>\n");
    wfs(tree);
     
    return 0;
}