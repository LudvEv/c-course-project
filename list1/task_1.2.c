#include <stdio.h>
#include "slist.h"

int first_integer(n) {
	int i;
	pslist list;
	list = list_new();
	for (i = 1; i < n + 1; i++) {
		slist_insert(list, i);
	}
	return list;
}

int main(void) {
	int n;
	scanf("%d", &n);
	pslist list;
	list = first_integer(n);
	return 0;
}