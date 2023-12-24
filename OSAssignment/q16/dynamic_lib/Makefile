CC=gcc
CFLAGS=-g -ggdb3 -Wall -fPIC
LDFLAGS=-ldynamic -I./ -L./ -lm

OBJS = add.o sub.o
DYNAMIC_LIB = $(PWD)/libdynamic.so

all: a.out

a.out: q16.o $(DYNAMIC_LIB)
	$(CC) $< $(CFLAGS) $(LDFLAGS) -Wl,-rpath=$(PWD) -o a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNAMIC_LIB): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

clean:
	rm -rf a.out *.o $(DYNAMIC_LIB)	

run:
	./a.out
