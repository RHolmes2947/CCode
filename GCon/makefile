CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall 
FILES = main.c student.c grade_converter.c
OUT_EXE = assin2


DEPS = student.h grade_converter.h


main.o: main.c $(DEPS)
	$(CC) $(CC_FLAGS) -c main.c -o main.o

student.o: student.c student.h
	$(CC) $(CC_FLAGS) -c student.c -o student.o

grade_converter.o: grade_converter.c grade_converter.h
	$(CC) $(CC_FLAGS) -c grade_converter.c -o grade_converter.o


$(OUT_EXE): main.o student.o grade_converter.o
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) main.o student.o grade_converter.o


clean:
	rm -f *.o core $(OUT_EXE) *~
