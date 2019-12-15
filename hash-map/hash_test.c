#include <stdio.h>
#include <stdlib.h>
#include "hash-map.h"
#define MAXSTR 1024
void test1()
{
	int a = 10;
	add("hallo mazafaka", &a);
	find("hallo mazafaka");	
}

void task()
{
	char* command = (char*)malloc(sizeof(char) * MAXSTR);
	char* name = (char*)malloc(sizeof(char) * MAXSTR);
	char* number = (char*)malloc(sizeof(char) * MAXSTR);

	while (scanf("%[^' ']%*c", command))
	{
		if (command == "INSERT")
		{
			scanf("%[^' ']%*c", name);
			scanf("%[^' ']%*c", number);
			add(name, number);
		}
		else if (command == "FIND")
		{
			scanf("%[^' ']%*c", name);
			find(name);
		}
		else
			printf("Sorry, i don't understand:(");
	}
	free(command);
	free(name);
	free(number);
}

int main()
{
	printf("test1>>>>\n");
	test1();
	return 0;
}