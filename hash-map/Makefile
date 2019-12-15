all: tlist

tlist: stest.o hash-map.o
	gcc stest.o hash-map.o -o tlist_test

stest.o:
	gcc -c hash_test.c -o stest.o

slist.o:
	gcc -c hash-map.c -o hash-map.o

clean:
	rm -rf *.o slist_test