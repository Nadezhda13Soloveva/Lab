CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: test

test: test.o
	$(CC) $(CFLAGS) -o test test.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f *.o test