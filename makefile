all: compile start

compile:
	g++ main.cpp -o a.out -lGL -lGLU -lglut

start:
	./a.out
