CC=cc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -D_XOPEN_SOURCE=600
OBJS=matte.o minmattefunk.o usage.o
PREFIX=/usr/local

matte: $(OBJS)
	    $(CC) -o matte $(OBJS)

matte.o: minmattefunk.h usage.h

clean:
	    rm matte $(OBJS)

install:
	    cp matte $(DESTDIR)$(PREFIX)/bin/matte

uninstall:
	    rm $(DESTDIR)$(PREFIX)/bin/matte
