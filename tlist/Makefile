all: tlist

tlist: stest.o tlist.o
	gcc stest.o tlist.o -o tlist_test

stest.o:
	gcc -c Test.c -o stest.o

slist.o:
	gcc -c tlist.c -o tlist.o

clean:
	rm -rf *.o slist_test