//
//  tlist.c
//
//  Created by Людвиковский Евгений Владиславович on 07.12.2019.
//  Copyright © 2019 Людвиковский Евгений Владиславович. All rights reserved.
//

#include "tlist.h"
#include <stdlib.h>
#include <stdio.h>

//create an empty list
ptlist tlist_new(void)
{
    ptlist list = malloc(sizeof(struct tlist));
    if (list == NULL)
        return NULL;
    list->list_size = 0;
    list->head = NULL;
    list->tail = NULL;
    
    return list;
}



//delete list
void tlist_delete(ptlist list)
{
    ptlist_entry head = list->head;
    ptlist_entry tdel;
    while (NULL != head)
    {
        sdel = head;
        head = sdel->next;
        free(sdel);
    }
    free(list);
}

//insert value in top of list
int unshift(ptlist list, int value)
{
    pslist_entry pnew = malloc(sizeof(struct slist_entry));
    if (pnew == NULL)
        return 0;
    pnew->next = list->head;
    pnew->prev = NULL;
    pnew->value = value;
    if (list->list_size == 0)
        list->tail = pnew
    else list->head->prev = pnew;
    list->head = pnew
    list->list_size++;
    return 1;
}

//extract value of the top of list in pointer
int shift(ptlist list, int* pointer)
{
    if (list->list_size == 0)
        printf("list is empty, nothing to extract");
        return 0;
    *pointer = list->head->value;
    return 1;
}

//insert value in the end of list
int push(ptlist list, int value)
{
    pslist_entry pnew = malloc(sizeof(struct slist_entry));
    if (pnew == NULL)
        return 0;
    pnew->prev = list->tail;
    pnew->next = NULL;
    pnew->value = value;
    if (list->list_size == 0)
        list->head = pnew
    else list->tail->next = pnew;
    list->tail = pnew
    list->list_size++;
    return 1;
}

//extract value of the end of list in pointer
int pop(ptlist list, int* pointer)
{
    if (list->list_size == 0)
        printf("list is empty, nothing to extract");
        return 0;
    *pointer = list->tail->value;
    return 1;
}

//reverse list
void reverse(ptlist* list)
{
    int i, temp;
    ptlist temp_list = tlist_new();
    for (i = 0; i < *list->list_size; i++) 
    {
        shift(*list, &temp)
        unshift(temp_list, temp)
    }
    tlist_delete(*list);
    tlist_new(*list);
    *list = temp_list;
    tlist_delete(tlist_delete);
} 