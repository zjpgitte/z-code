cc=gcc 
file=qsort 
fileList=qsort.o test.o Stack.o
file2=clean 

$(file):$(fileList)
	$(cc) $^ -o $@
%.o:%.c
	$(cc) -c $<

.PHONY:$(file2)
$(file2):
	rm -f *.o qsort
