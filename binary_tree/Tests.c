#include <stdio.h>
#include "tree.h"


int main(void)
{
    pbin_tree tree = initTree();
    treeInsert(tree, 1, 1);
    treeInsert(tree, 2, 1);
    treeInsert(tree, 3, 1);
    treeInsert(tree, 4, 1);
    treeInsert(tree, 5, 1);
    treeInsert(tree, 6, 1);
    treeInsert(tree, 7, 1);
    treeInsert(tree, 8, 1);
    
    wfs(tree);
    treeInsert(tree, 3, 2);
    wfs(tree);
    destroyTree(tree);
    wfs(tree); 
     
    return 0;
}