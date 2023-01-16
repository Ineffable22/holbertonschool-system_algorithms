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

2:
	$(CC) $(CFLAGS) -o 2-dijkstra_graph test/2-main.c 2-dijkstra_graph.c $(LIB)
	./2-dijkstra_graph
	rm 2-dijkstra_graph

2val:
	$(CC) $(CFLAGS) -o 2-dijkstra_graph test/2-main.c 2-dijkstra_graph.c $(LIB)
	valgrind ./2-dijkstra_graph
	rm 2-dijkstra_graph

2.1:
	$(CC) $(CFLAGS) -o 2-dijkstra_graph test/2-main_1.c 2-dijkstra_graph.c $(LIB)
	./2-dijkstra_graph
	rm 2-dijkstra_graph

2.1val:
	$(CC) $(CFLAGS) -o 2-dijkstra_graph test/2-main_1.c 2-dijkstra_graph.c $(LIB)
	valgrind ./2-dijkstra_graph
	rm 2-dijkstra_graph

betty:
	betty test/*c *.c *.h
