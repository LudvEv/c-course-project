#include <stdio.h>
#include "tlist.h"

int test1()
{
	tlist list = tlist_new();
	push(list, 1);
	push(list, 3);
	push(list, 3);
	push(list, 4);
	tlist_print(list);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}