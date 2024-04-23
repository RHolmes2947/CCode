CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall 
FILES = main.c eight_queens.c
OUT_EXE = lab5

build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

clean:
	rm -f *.o core *.exe *~

rebuild: clean build
