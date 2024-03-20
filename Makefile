CC = clang
CFLAGS = -g -lGL -lglut -lGLEW

main: main.c
	${CC} ${CFLAGS} main.c -o target/main

all: main
  
clean: 
	rm -rf target
