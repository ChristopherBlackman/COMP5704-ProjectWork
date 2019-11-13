# -Wall 	: strict compiler
#  -g   	: debugging
#  -pthread	: glibc-2.2+ {malloc,calloc,realloc,free,posix_memalign} are thread safe}

FLAGS = -g -Wall -pthread -fopenmp
LIBRARIES = ./lib

build: main.o
	g++ $(FLAGS) -o main main.o -I $(LIBRARIES)

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -I $(LIBRARIES)

clean :
	rm -rf *.o
	rm -rf main
