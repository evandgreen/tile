CC=gcc
CFLAGS = -Wall -g
LDFLAGS = -lX11
VERSION = 0.1

tile: tile.c
	${CC} ${CFLAGS} tile.c -o $@ ${LDFLAGS}
install: tile
	cp -f tile /usr/bin
uninstall:
	rm -f /usr/bin/tile
