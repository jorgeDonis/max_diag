COMPILER = g++
ARGS = -Wall -g
OBJ_FOLDER = obj/

diag: ${OBJ_FOLDER}main.o ${OBJ_FOLDER}Matrix.o
	${COMPILER} ${ARGS} ${OBJ_FOLDER}main.o ${OBJ_FOLDER}Matrix.o -o diag

${OBJ_FOLDER}main.o: main.cc
	${COMPILER} ${ARGS} -c main.cc -o ${OBJ_FOLDER}main.o

${OBJ_FOLDER}Matrix.o: Matrix.cc Matrix.h
	${COMPILER} ${ARGS} -c Matrix.cc -o ${OBJ_FOLDER}Matrix.o

clean:
	rm -f ./*.o


