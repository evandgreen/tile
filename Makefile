CC=gcc
CFLAGS = -Wall -g

twix: twix.c
	$(CC) $(CFLAGS) -o $(@)
