all:
	g++  -std=c++14 -g -o test test.cc
clean:
	rm -rf test test.o
