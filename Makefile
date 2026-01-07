CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = Allocator_Arena_v1

# The default 'make' command
all: $(TARGET)

$(TARGET): arena.c main.c arena.h
	$(CC) $(CFLAGS) arena.c main.c -o $(TARGET)

# Clean up the binary
clean:
	rm -f $(TARGET)
