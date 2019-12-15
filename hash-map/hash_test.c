#include <stdio.h>
#include "hash-map.h"

void test1()
{
	int a = 10;
	add("hallo mazafaka", &a);
	find("hallo mazafaka");	
}

int main()
{
	printf("test1>>>>\n");
	test1();
	return 0;
}