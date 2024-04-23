CC=gcc
CFLAGS=-Wall


TARGET=main


SRC = 2DMenu.c Print_Array.c Reverse_array.c Sort_array.c Randomize_array.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)
