#include <stdio.h>
#include "tlist.h"

int test1()
{
	ptlist list = tlist_new();
	tlist_print(list);
	push(list, 1);
	push(list, 3);
	push(list, 3);
	push(list, 4);
	tlist_print(list);
	tlist_delete(list);
}

int test2()
{
	ptlist list = tlist_new();
	int a;
	tlist_print(list);
	push(list, 1);
	push(list, 3);
	push(list, 3);
	push(list, 4);
	tlist_print(list);
	pop(list, &a);
	pop(list, &a);
	pop(list, &a);
	pop(list, &a);
	pop(list, &a);
	pop(list, &a);
	tlist_print(list);
	tlist_delete(list);
	
}

int main(int argc, char const *argv[])
{
	printf("Test1 >>>>>>>");
	test1();
	printf("Test2 >>>>>>>");
	test2();
	return 0;
}