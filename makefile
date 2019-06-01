COMPILER = g++
ARGS = -Wall -g

diag: main.o Matrix.o
	${COMPILER} ${ARGS} main.o Matrix.o -o diag

main.o: main.cc
	${COMPILER} ${ARGS} -c main.cc -o main.o

Maze.o: Maze.cc Maze.h
	${COMPILER} ${ARGS} -c Maze.cc -o Maze.o

clean:
	rm -f ./*.o


