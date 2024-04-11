CC=gcc
CFLAGS = -Wall -g
LDFLAGS = -lX11
VERSION = 0.1

twix: twix.c
	${CC} ${CFLAGS} twix.c -o $@ ${LDFLAGS}
install: twix
	cp -f twix /usr/bin
uninstall:
	rm -f /usr/bin/twix
