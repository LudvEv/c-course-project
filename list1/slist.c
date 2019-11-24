//
//  slist.c
//  hardString
//
//  Created by Панышев Александр Сергеевич on 24.11.2019.
//  Copyright © 2019 Панышев Александр Сергеевич. All rights reserved.
//

#include "slist.h"

pslist_entry slist_new(void)
{
    pslist list = malloc(sizeof(struct slist));
    if (NULL == list)
        return NULL;
    list->list_size = 0;
    list->head = NULL;
    
    return list;
}

pslist_entry slist_pop(pslist list)
{
    
    return NULL;
}


void slist_delete(pslist list)
{
    pslist_entry head;
    while (NULL != (head = slist_pop(list)))
    {
        free(head);
    }
    
    free(list);
}


int slist_insert(pslist list, int value)
{
    struct slist_entry *pnew = malloc(sizeof(struct slist_entry));
    if (pnew == NULL)
    return -1;
    pnew->next = list->head;
    pnew->value = value;
    list->head = pnew;
    list->list_size++;
    return 0;
}

int slist_remove(pslist list, int value)
{
    return NULL;
}

void slist_print(pslist list)
{
    pslist_entry pcurrent = list->head;
    printf("List: \n");
    while (pcurrent != NULL)
    {
       printf("> %d\n", pcurrent->value);
       pcurrent = pcurrent->next;
    }
}
