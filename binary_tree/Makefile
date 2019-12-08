all: tree

tree: stest.o tree.o
	gcc stest.o tree.o -o tree_test

stest.o:
	gcc -c Tests.c -o stest.o

tree.o:
	gcc -c tree.c -o tree.o

clean:
	rm -rf *.o tree_test