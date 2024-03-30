CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: generator program

generator: generator.c person.h
	$(CC) $(CFLAGS) -o generator generator.c

program: program.c person.h
	$(CC) $(CFLAGS) -o program program.c

.PHONY: clean

clean:
	rm -f *.o

.PHONY: cleanall

cleanall:
	rm -f generator program

