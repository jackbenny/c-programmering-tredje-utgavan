CC=cc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -D_XOPEN_SOURCE=600

matte: matte.o minmattefunk.o usage.o
	$(CC) -o matte matte.o minmattefunk.o usage.o

matte.o: matte.c minmattefunk.h usage.h
	$(CC) $(CFLAGS) -c matte.c

minmattefunk.o: minmattefunk.c
	$(CC) $(CFLAGS) -c minmattefunk.c

usage.o: usage.c
	$(CC) $(CFLAGS) -c usage.c

clean:
	rm matte minmattefunk.o matte.o usage.o
