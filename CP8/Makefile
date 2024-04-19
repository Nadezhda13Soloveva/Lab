CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: program

program: program.o list.o iterator.o
	$(CC) $(CFLAGS) -o program program.o list.o iterator.o

program.o: program.c struct.h
	$(CC) $(CFLAGS) -c program.c

list.o: list.c struct.h
	$(CC) $(CFLAGS) -c list.c

iterator.o: iterator.c struct.h
	$(CC) $(CFLAGS) -c iterator.c

valgrind: program
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./generator out

clean:
	rm -f *.o program

