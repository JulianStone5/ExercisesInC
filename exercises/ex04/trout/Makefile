# trout: trout.h trout.c util.c main.c
# 	gcc -g -o trout main.c trout.c util.c
trout: main.o trout.o util.o
	gcc -Wall main.o trout.o util.o -o trout
main.o: main.c trout.h util.h
	gcc -c main.c
util.o: util.c util.h
	gcc -c util.c
trout.o: trout.c trout.h
	gcc -c trout.c
