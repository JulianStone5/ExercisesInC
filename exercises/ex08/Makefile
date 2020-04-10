all: ex_compile word_count

ex_compile: ex_compile.c
	gcc ex_compile.c -Wall -o ex_compile `pkg-config --cflags --libs glib-2.0`
word_count: word_count.c
	gcc word_count.c -Wall -o word_count `pkg-config --cflags --libs glib-2.0`
