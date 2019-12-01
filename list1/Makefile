all: list1

list1: stest.o slist.o
	gcc stest.o slist.o -o slist_test

stest.o:
	gcc -c Tests.c -o stest.o

slist.o:
	gcc -c slist.c -o slist.o

clean:
	rm -rf *.o slist_test