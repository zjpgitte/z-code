heap:test.o heap.o
	gcc test.o heap.o -o heap
test.o:test.c
	gcc -c test.c -o test.o
heap.o:heap.c
	gcc -c heap.c -o heap.o
.PHONY:clean
clean:
	rm -f heap test.o heap.o
