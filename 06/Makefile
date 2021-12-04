CC = gcc
CFLAGS = -Wall -I.
LDFLAGS =
OBJFILES = parser.o symtable.o error.o hack.o main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~