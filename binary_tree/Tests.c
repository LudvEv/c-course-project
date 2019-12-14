#include <stdio.h>
#include "tree.h"


int main(void)
{
    pbin_tree tree = initTree();
    treeInsert(tree, 5, 2);
    treeInsert(tree, 1, 2);
    treeInsert(tree, 3, 2);
    treeInsert(tree, 6, 2);
    printf("%d\n>>>>>>>\n", CountTree(tree));
    dfs(tree);
    printf(">>>>>>>>\n");
    wfs(tree);
     
    return 0;
}