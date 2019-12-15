#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash-map.h"


PENTRY hash_map[N];

long long int exp(int n)
{
	long long int exp = 1;

	while (n > 0)
	{
		exp = exp * 10;
		n--;
	}
	return exp;
}

long long int hash(char* key)
{
	long long int int_key = 0;
	int  i = 0;

	while (('A' >= key[i]) & (key[i] <= 'Z'))
	{
		int_key += key[i] * exp(i);
		i++;
	}
	return int_key ^ N;
}

void hash_map_init(void)
{

}

void hash_map_deinit(void)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (NULL != hash_map[i]->number)
		{
			free(hash_map[i]->number);
			free(hash_map[i]->name);
		}
	}
}

void add(char* name, int* number)
{
	unsigned int index = hash(name) % N;
	if (NULL != hash_map[index]->name)
		printf("Changed. Old value = %li\n", *(hash_map[index]->number));
	else printf("OK");
	hash_map[index]->name = name;
	hash_map[index]->number = number;
}

void find(char* name)
{
	unsigned int index = hash(name) % N;
	if (NULL != hash_map[index]->name)
		printf("%li", *(hash_map[index]->number));
	else printf("NO");
	
}
