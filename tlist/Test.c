#include <stdio.h>
#include "tlist.h"

void test1()
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

void test2()
{
	ptlist list = tlist_new();
	int a = 0;
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

void test3()
{
	ptlist list = tlist_new();
	int a = 0;
	tlist_print(list);
	push(list, 1);
	push(list, 3);
	push(list, 3);
	push(list, 4);
	tlist_print(list);
	shift(list, &a);
	shift(list, &a);
	shift(list, &a);
	shift(list, &a);
	shift(list, &a);
	shift(list, &a);
	tlist_print(list);
	tlist_delete(list);

}

void test4()
{
	ptlist list = tlist_new();
	int a = 0;
	tlist_print(list);
	push(list, 1);
	push(list, 3);
	push(list, 3);
	push(list, 4);
	tlist_print(list);
	reverse(list);
	tlist_print(list);
}

void test5()
{
	ptlist list = tlist_new();
	tlist_print(list);
	unshift(list, 1);
	unshift(list, 3);
	unshift(list, 3);
	unshift(list, 4);
	tlist_print(list);
	tlist_delete(list);
}

void test6()
{
	ptlist list = tlist_new();
	int a = 0;
	shift(list, &a);
	pop(list, &a);
	reverse(list);
	tlist_print(list);
}



int main(int argc, char const *argv[])
{
	printf("Test1 >>>>>>>");
	test1();
	printf("Test2 >>>>>>>");
	test2();
	printf("Test3 >>>>>>>");
	test3();
	printf("Test4 >>>>>>>");
	test4();
	printf("Test5 >>>>>>>");
	test5();
	printf("Test6 >>>>>>>");
	test6();
	return 0;
}