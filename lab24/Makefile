CC = gcc
CFLAGS = -std=c99 -Wall -pedantic
LIBS=-lm

all: lab24

lab24: lab24.o 
	$(CC) $(CFLAGS) -o lab24 lab24.o $(LIBS)

lab24.o: lab24.c 
	$(CC) $(CFLAGS) -c lab24.c

valgrind: lab24
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab24 out

clean:
	rm -f *.o lab24