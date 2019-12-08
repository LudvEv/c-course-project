//
//  slist.h
//  hardString
//
//  Created by Панышев Александр Сергеевич on 24.11.2019.
//  Copyright © 2019 Панышев Александр Сергеевич. All rights reserved.
//

#pragma once

//Forward declaration
typedef struct slist_entry *pslist_entry;
typedef struct slist *pslist;

struct slist_entry
{
    pslist_entry next;
    int value;
};

struct slist
{
    int list_size;
    pslist_entry head;
};	

/*
 * Creates an empty list
 * Params: none
 * Return pointer to the list
 */
pslist slist_new(void);


/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */
void slist_delete(pslist list);


/*
 * Adds an item to the top of the list
 * Params: list - pointer to the list
 *         value - inserted value
 * Returns: 0 - success
 *          -1 - not success
 */
int slist_insert(pslist list, int value);


/*
 * Deletes all elements containing the given number
 * Params: list - pointer to the list
 *         value - deleted value
 * Returns: 0 - success
 *          -1 - not success
 */
int slist_remove(pslist list, int value);



void slist_print(pslist list);
