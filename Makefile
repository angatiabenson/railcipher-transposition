CC=gcc
CFLAGS=-I. -g -w
DEPS = railcipher.h
OBJ = railcipher.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

railcipher: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
