CXX = g++
CXXFLAGS = -g -Wall -std=c++11
FLAGS = -g -Wall -o
ifeq ($(OS), Windows_NT)
    SHARED-LIB = liblab-09.dll
else
    SHARED-LIB = liblab-09.so
endif
TESTS_PATH = ../tests/
EXECUTABLE = main
BUILD_FOLDER_PATH = ../build/
LIBS_PATH = ./libs

build-lib:
	$(CXX) *.c -I$(LIBS_PATH) -shared -fPIC $(CXXFLAGS) -o $(BUILD_FOLDER_PATH)$(SHARED-LIB)

build-exe:
	$(CXX) *.c -I$(LIBS_PATH) $(CXXFLAGS) -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

run: build-exe
	cls &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)


move:
	cp $(SHARED-LIB) ../tests
