//
//  hash_map.h
//
//  Created by Людвиковский Евгений Владиславович on 07.12.2019.
//  Copyright © 2019 Людвиковский Евгений Владиславович. All rights reserved.
//

#pragma once
#define N 16

//Forward declaration

typedef struct _ENTRY
{
void* address;
char* function_name;
} ENTRY, *PENTRY;

ENTRY g_hash_map[N];

/*
 * Creates an empty hash_map
 * Params: none
 * Returns nothing
 */
void hash_map_init(void);

/*
 * Deletes hash_map
 * Params: none
 * Returns nothing
 */
void hash_map_deinit(void);

/*
 * Adds element
 * Params:pointer to address and to function_name
 * Returns index of element
 */
unsigned int add(void* address, char* function_name);

/*
 * Removes element
 * Params:pointer to address
 * Returns -1 if unsucces and 0 if success
 */
unsigned int remove(void* address);

/*
 * Finds an element by addres
 * Params:pointer to address
 * Returns index of element
 */
PENTRY find(void* address);