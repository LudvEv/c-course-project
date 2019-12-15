#include <stdio.h>
#include "tree.h"

//рекурсивный обход
void prefix(pbin_tree curr)
{
    if (!curr)
        return;
    printf("%d ", curr->value);
    prefix(curr->left);
    prefix(curr->right);
}

int main(void)
{
     
    return 0;
}