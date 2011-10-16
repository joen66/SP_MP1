CC=gcc
CFLAGS=-Wall -g
all: stage/borrow

stage/borrow: borrow.c sharedfunc.o
	$(CC) borrow.c sharedfunc.o $(CFLAGS) -o stage/borrow
sharedfunc.o: sharedfunc.c sharedfunc.h
	$(CC) $(CFLAGS) -c sharedfunc.c
clean:
	rm -f stage/*
