CC=cc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -D_XOPEN_SOURCE=600

matte: matte.o minmattefunk.o usage.o
	$(CC) -o matte matte.o minmattefunk.o usage.o

matte.o: minmattefunk.h usage.h

clean:
	rm matte minmattefunk.o matte.o usage.o
