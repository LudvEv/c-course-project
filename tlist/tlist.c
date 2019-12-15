
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
    while (list->list_size > 0)
    {
        tdel = head;
        head = tdel->next;
        free(tdel);
        list->list_size--;
    }
    free(list);
}

void tlist_delete_elements(ptlist list)
{
    ptlist_entry head = list->head;
    ptlist_entry tdel;
    while (list->list_size > 0)
    {
        tdel = head;
        head = tdel->next;
        free(tdel);
        list->list_size--;
    }
}


//insert value in top of list
int unshift(ptlist list, int value)
{
    ptlist_entry pnew = malloc(sizeof(struct tlist_entry));
    if (pnew == NULL)
        return 0;
    pnew->next = list->head;
    pnew->prev = NULL;
    pnew->value = value;

    list->head = pnew;
    list->head->prev = pnew->prev;
    list->head->next = pnew->next;
    list->head->value = pnew->value;
    if (list->list_size == 0)
        list->tail = pnew;
    else list->head->next->prev = pnew;
    list->list_size++;
    return 1;
}

//extract value of the top of list in pointer
int shift(ptlist list, int* pointer)
{
    ptlist_entry temp;
    if (list->list_size == 0)
    {
        printf("list is empty, nothing to extract");
        return 0;
    }
    *pointer = list->head->value;
    temp = list->head;
    temp->next = list->head->next;

    list->head = temp->next;
    free(temp);
    list->list_size--;
    if (list->list_size > 1)
        list->head->next->prev = NULL;

    return 1;
}

//insert value in the end of list
int push(ptlist list, int value)
{
    ptlist_entry pnew = malloc(sizeof(struct tlist_entry));
    if (pnew == NULL)
        return 0;
    pnew->prev = list->tail;
    pnew->next = NULL;
    pnew->value = value;
    
    list->tail = pnew;
    list->tail->prev = pnew->prev;
    list->tail->next = pnew->next;
    list->tail->value = pnew->value;
    if (list->list_size == 0)
        list->head = pnew;
    else list->tail->prev->next = pnew;
    list->list_size++;
    return 1;
}

//extract value of the end of list in pointer
int pop(ptlist list, int* pointer)
{
    ptlist_entry temp;
    if (list->list_size == 0)
    {
        printf("list is empty, nothing to extract");
        return 0;
    }
    *pointer = list->tail->value;
    temp = list->tail;
    temp->prev = list->tail->prev;
    
    list->tail = temp->prev;
    free(temp);
    list->list_size--;
    if (list->list_size > 1)
        list->tail->prev->next = NULL;
    
    return 1;
}

//reverse list
void reverse(ptlist list)
{
    int i, temp;
    ptlist temp_list = tlist_new();
    for (i = 0; i < list->list_size; i++)
    {
        shift(list, &temp);
        unshift(temp_list, temp);
    }
    tlist_delete_elements(list);
    list->head = temp_list->head;
    list->tail = temp_list->tail;
    tlist_delete(temp_list);
}

//print list
void tlist_print(ptlist list)
{
    ptlist_entry pcurrent = list->head;
    int t = list->list_size;

    printf("List: ");
    while (t > 0)
    {
        printf("> %d <", pcurrent->value);
        pcurrent = pcurrent->next;
        t--;
    }
    printf("\n");
}
