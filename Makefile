CC = clang
CFLAGS = -g -lGL -lglut -lGLEW

FILES = main.c
SRC_FILES = $(foreach file,${FILES},src/${file})
OBJECT_FILES = $(foreach file,${FILES},target/$(subst .c,.o,${file}))

all: prep main

${OBJECT_FILES} : prep ${SRC_FILES}
	${CC} -c ${CFLAGS} $(subst target,src,$(subst .o,.c,$@)) -o $@

main: ${OBJECT_FILES}
	${CC} ${CFLAGS} ${OBJECT_FILES} -o target/main

prep:
	mkdir -p target

run: all
	./target/main

clean: 
	rm -rf target

