CC=gcc

SRC_DIR=src
BUILD_DIR=build

.PHONY: all encoder decoder clean always

all: encoder decoder

encoder: always
	${CC} ${SRC_DIR}/encode.c -o ${BUILD_DIR}/encoder

decoder: always
	${CC} ${SRC_DIR}/decode.c -o ${BUILD_DIR}/decoder

clean:
	rm -rf ${BUILD_DIR}/*

always:
	mkdir -p ${BUILD_DIR}