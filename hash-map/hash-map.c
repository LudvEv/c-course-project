#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


ENTRY g_hash_map[N];

int hash(unsigned long long int key)
{
return key ^ N;
}

void hash_map_init(void)
{

}

void hash_map_deinit(void)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (NULL != g_hash_map[i]->function_name)
			free(g_hash_map[i]->function_name);
	}
}

char* make_str(char* str)
{
	char* new_str = (char *)malloc(strlen(str) + 1);
	if (NULL == new_str)
	{
		return NULL;
	}
	strcpy(new_str, str);
	return new_str;
}

unsigned int add(void* address, char* function_name)
{
	unsigned int index = hash(address);
	if (NULL != g_hash_map[index]->address)
	{
		printf("Collision!\n");
		return -1;
	}
	g_hash_map[index]->address = address;
	g_hash_map[index]->function_name = make_str(function_name);
	return index;
}

unsigned int del(void* address)
{
	unsigned int index = hash(address);
	if (NULL == g_hash_map[index]->address)
	{
		return -1;
	}
	g_hash_map[index]->address = NULL;
	if (NULL != g_hash_map[index]->function_name)
	free(g_hash_map[index]->function_name);
	g_hash_map[index]->function_name = NULL;
	return 0;
}

PENTRY find(void* address)
{
	unsigned int index = hash(address);
	return (NULL != g_hash_map[index]->address) ? &g_hash_map[index] : NULL;
}
