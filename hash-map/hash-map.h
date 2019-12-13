//
//  hash_map.h
//
//  Created by Людвиковский Евгений Владиславович on 07.12.2019.
//  Copyright © 2019 Людвиковский Евгений Владиславович. All rights reserved.
//

#pragma once
#define N 1024

//Forward declaration

typedef struct _ENTRY
{
	char* name;
	long int* number;
} ENTRY, *PENTRY;

PENTRY hash_map[N];

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
void add(char* name, int* number);

/*
 * Finds an element by addres
 * Params:pointer to address
 * Returns index of element
 */
void find(char* name);