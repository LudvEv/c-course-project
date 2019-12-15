//
//  tlist.h
//
//  Created by Людвиковский Евгений Владиславович on 07.12.2019.
//  Copyright © 2019 Людвиковский Евгений Владиславович. All rights reserved.
//

#pragma once

//Forward declaration
typedef struct tlist_entry *ptlist_entry;
typedef struct tlist *ptlist;

struct tlist_entry
{
	ptlist_entry next;
	ptlist_entry prev;
	int value;
};

struct tlist
{
	int list_size;
	ptlist_entry head;
	ptlist_entry tail;
};

/*
 * Creates an empty list
 * Params: none
 * Return pointer to the list
 */
ptlist tlist_new(void);


/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */
void tlist_delete(ptlist list);


/*
 * Adds an item to the top of the list
 * Params: list - pointer to the list
 *         value - inserted value
 * Returns: 1 - success
 *          0 - not success
 */
int unshift(ptlist list, int value);

/*
 * Extracts an item of the top of the list
 * Params: list - pointer to the list
 *         value - inserted value
 * Returns: 1 - success
 *          0 - not success
 */
int shift(ptlist list, int* pointer);

/*
 * Extracts an item of the end of the list
 * Params: list - pointer to the list
 *         pointer - inserted pointer
 * Returns: 1 - success
 *          0 - not success
 */
int pop(ptlist list, int* pointer);

/*
 * Adds an item to the end of the list
 * Params: list - pointer to the list
 *         pointer - inserted pointer
 * Returns: 1 - success
 *          0 - not success
 */
int push(ptlist list, int value);

/*
 * Reverses the list
 * Params: list - pointer to the list
 * Returns: 1 - success
 *          0 - not success
 */
void reverse(ptlist list);

/*
 * Prints all list items
 * Params: list - pointer to the list
 * Returns: none
 */
void tlist_print(ptlist list);







