CC = gcc
CFLAGS = -Wall -g -std=c99

all: scramble

scramble: unscramble.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -r scramble scramble.dSYM
