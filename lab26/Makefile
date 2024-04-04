CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: program

program: program.o list.o
	$(CC) $(CFLAGS) -o program program.o list.o

program.o: program.c list.h
	$(CC) $(CFLAGS) -c program.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -f *.o program