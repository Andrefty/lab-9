CC = gcc
CFLAGS = -g -Wall
FLAGS = -g -Wall -o
EXECUTABLE = lab
BUILD_FOLDER_PATH = ./build/

build: build-dir
	cd ./src &&\
	make build-lib

test: build
	cd ./tests &&\
	make test

test-c1: build
	cd ./tests &&\
	make test-c1

test-c2: build
	cd ./tests &&\
	make test-c2

test-c3: build
	cd ./tests &&\
	make test-c3

test-heap: build
	cd ./tests &&\
	make test-heap

build-dir: clean
	mkdir $(BUILD_FOLDER_PATH)

single-run: build-dir
	cd ./src &&\
	make run

clean:
	rm -rf $(BUILD_FOLDER_PATH)
