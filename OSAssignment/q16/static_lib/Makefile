CC=gcc
CFLAGS=-g -ggdb3 -Wall
LDFLAGS=-lm
AR=ar
RANLIB=ranlib

OBJS = add.o sub.o
STATIC_LIB = static_Lib.a 

all: a.out

a.out: q16.o $(STATIC_LIB)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -static -o a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJS)
	$(AR) rc $@ $^
	$(RANLIB) $@

clean:
	rm -rf a.out *.o $(STATIC_LIB)
run:
	./a.out
