//
//  slist.c
//  hardString
//
//  Created by Панышев Александр Сергеевич on 24.11.2019.
//  Copyright © 2019 Панышев Александр Сергеевич. All rights reserved.
//ls

#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
//create an empty list
pslist slist_new(void)
{
    pslist list = malloc(sizeof(struct slist));
    if (list == NULL)
        return NULL;
    list->list_size = 0;
    list->head = NULL;
    
    return list;
}



//delete list
void slist_delete(pslist list)
{
    pslist_entry head = list->head;
    pslist_entry sdel;
    while (head != NULL)
    {
        sdel = head;
        head = sdel->next;
        free(sdel);
    }
    free(list);
}

//insert value in head of list
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
    pslist_entry pcurrent = list->head;
    int count = 0;
    while (pcurrent != NULL)
    {
        if (pcurrent->value == value)
        {
            if (pcurrent->next != NULL)
            {
                pcurrent->value = pcurrent->next->value;
                pcurrent->next = pcurrent->next->next;
                free(pcurrent->next);
            }
            else
            {
                pcurrent = list->head;
                while (pcurrent != NULL)
                {
                    if (pcurrent->next->next == NULL)
                    {
                        pcurrent->next = NULL;
                        free(pcurrent->next);
                        break;
                    }
                    pcurrent = pcurrent->next;
                }
            }
            count++;
        }
        else
            pcurrent = pcurrent->next;
    }
    return count;
}

//print list
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
