CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = array.util.c array.util.h main.c
TARGET = maintest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET)

run: maintest
	./maintest < teste.txt > saida.txt