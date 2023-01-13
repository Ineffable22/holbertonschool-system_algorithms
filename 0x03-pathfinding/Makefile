CC = gcc
CFLAGS = -no-pie -Wall -Wextra -Werror -pedantic -I ./
LIB = libqueues.a libgraphs.a

0:
	$(CC) $(CFLAGS) -o 0-backtracking_array test/0-main.c 0-backtracking_array.c $(LIB)
	./0-backtracking_array
	rm 0-backtracking_array

0val:
	$(CC) $(CFLAGS) -o 0-backtracking_array test/0-main.c 0-backtracking_array.c $(LIB)
	valgrind ./0-backtracking_array
	rm 0-backtracking_array

1:
	$(CC) $(CFLAGS) -o 1-backtracking_graph test/1-main.c 1-backtracking_graph.c $(LIB)
	./1-backtracking_graph
	rm 1-backtracking_graph

1val:
	$(CC) $(CFLAGS) -o 1-backtracking_graph test/1-main.c 1-backtracking_graph.c $(LIB)
	valgrind ./1-backtracking_graph
	rm 1-backtracking_graph

betty:
	betty test/*c *.c *.h
