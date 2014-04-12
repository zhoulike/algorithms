objects = test.o graph.o

test : $(objects)
	g++ -o test $(objects)

test.o : graph.h
graph.o: graph.h

.PHONY : clean

clean :
	rm test $(objects)
