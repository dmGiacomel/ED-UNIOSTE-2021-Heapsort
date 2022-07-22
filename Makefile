CC = gcc
CFLAGS = -Wall
DEPS = array.util.h
OBJ = main.o array.util.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	gcc $(CFLAGS) -o $@ $^