# -Wall 	: strict compiler
#  -g   	: debugging
#  -pthread	: glibc-2.2+ {malloc,calloc,realloc,free,posix_memalign} are thread safe}

FLAGS = -Wall -pthread -fopenmp -lm -std=c++11
LIBRARIES = ./lib

build: main.o a_forest.o utils.h
	g++ $(FLAGS) -o main main.o a_forest.o -I $(LIBRARIES)

main.o: main.cpp utils.h
	g++ $(FLAGS) -c main.cpp -I $(LIBRARIES)

a_forest.o : a_forest.cpp utils.h
	g++ $(FLAGS) -c a_forest.cpp -I $(LIBRARIES)

clean :
	rm -rf *.o
	rm -rf main
