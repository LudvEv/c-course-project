#include <stdio.h>
#include "slist.h"

int test1()
{
    pslist list;
    list = slist_new();
    printf("List created! %p\n", list);
    slist_insert(list, 10);
    slist_insert(list, 12);
    slist_insert(list, 14);
    slist_print(list);
    slist_delete(list);
    return 0;
}

int test2()
{
    pslist list = slist_new();
    if (NULL != list->head)
        goto error;
    if (0 != list->list_size)
        goto error;
    slist_delete(list);
    return 0;
    error:
        slist_delete(list);
        return -1;
}

int test3()
{
    pslist list = slist_new();
    slist_insert(list, 4);
    slist_insert(list, 5);
    slist_insert(list, 4);
    slist_remove(list, 1);
    slist_remove(list, 6);
    slist_remove(list, 4);
    int result = (list->list_size != 1)
    if (list->list_size != 1) {
        result = -1;
    }
    else {
        result = 0;
    }
    slist_delete(list);
    return result;
}

int main(void)
{
    printf("%d %d %d",test1() test2() test3());
    return 0;
}