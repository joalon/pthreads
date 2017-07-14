CFLAGS=-g -ansi -pedantic -Wall -std=c99
LDFLAGS=-pthread

all:
	gcc $(CFLAGS) $(LDFLAGS) threads.c -o threads

clean:
	rm threads
