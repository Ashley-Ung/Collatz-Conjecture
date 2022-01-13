CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean valgrind

all: bin bin/testCode  

bin: 
	mkdir -p bin

bin/testCode: bin/testCode.o
	${CC} ${CFLAGS} bin/testCode.o -o bin/testCode

bin/testCode.o: src/testCode.c
	${CC} ${CFLAGS} -c src/testCode.c -o bin/testCode.o

clean:
	rm -rf bin/*.o bin/testCode