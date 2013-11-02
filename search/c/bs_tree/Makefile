objects = test.o bs_tree.o

test : $(objects)
	gcc -o test $(objects)

test.o : bs_tree.h
bs_tree.o : bs_tree.h

.PHONY : clean

clean :
	rm test $(objects)
