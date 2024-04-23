CC = gcc
CC_FLAGS = -g -ansi -pedantic -W -Wall -std=c11
FILES = StuRes.c
OUT_EXE = Assign1

build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

clean:
	rm -f *.o core *.exe *~

rebuild: clean build
