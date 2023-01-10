# 0x03-pathfinding

# Files

### 0. Backtracking - Array
### [0-backtracking_array.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x03-pathfinding/0-backtracking_array.c)

```C
/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
    int x;
    int y;
} point_t;

```

### 1. Backtracking - Graph
### [1-backtracking_graph.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x03-pathfinding/1-backtracking_graph.c)

```C
alex@~/0x03-pathfinding$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        point_t *point = (point_t *)dequeue(path);
        printf(" [%d, %d]\n", point->x, point->y);
        free(point);
    }
    free(path);
}

/**
 * main - Backtracking using an array. Here the array is chosen to demonstrate
 * that Backtracking is a really bad algorithm. The target point is just
 * down-right from the starting point, but since we first check the right cell,
 * then top, then left, then bottom, our algo will almost go through the whole
 * maze before finding a path.
 * Don't use backtracking. Backtracking is bad.
 */
int main(void)
{
    char *map[21] = {
        "111111111111111111111",
        "101000000000001000001",
        "101011111111101110101",
        "100010000010001000101",
        "111111111010111011101",
        "101000000010100010001",
        "101011111010111011111",
        "101000001010001000001",
        "101110111011101111101",
        "101000001000100000101",
        "101011111110111110101",
        "101000000010000010001",
        "101111101111101111101",
        "000000001000001000001",
        "111011111010101011111",
        "100010100010101000001",
        "101110101111111110111",
        "100000101000000000001",
        "101111101011111111101",
        "100000100000000010001",
        "111110111111111111111"
    };
    point_t start = { 0, 13 };
    point_t target = { 5, 20 };
    queue_t *path;

    path = backtracking_array((char **)map, 21, 21, &start, &target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);

    return (EXIT_SUCCESS);
}
alex@~/0x03-pathfinding$ gcc -o 0-backtracking_array -Wall -Wextra -Werror -pedantic 0-main.c 0-backtracking_array.c -lqueues
alex@~/0x03-pathfinding$ ./0-backtracking_array 
Checking coordinates [0, 13]
Checking coordinates [1, 13]
Checking coordinates [2, 13]
Checking coordinates [3, 13]
Checking coordinates [4, 13]
Checking coordinates [5, 13]
Checking coordinates [6, 13]
Checking coordinates [7, 13]
Checking coordinates [7, 12]
Checking coordinates [7, 11]
Checking coordinates [8, 11]
Checking coordinates [9, 11]
Checking coordinates [6, 11]
Checking coordinates [5, 11]
Checking coordinates [4, 11]
Checking coordinates [3, 11]
Checking coordinates [3, 10]
Checking coordinates [3, 9]
Checking coordinates [4, 9]
Checking coordinates [5, 9]
Checking coordinates [6, 9]
Checking coordinates [7, 9]
Checking coordinates [5, 8]
Checking coordinates [5, 7]
Checking coordinates [6, 7]
Checking coordinates [7, 7]
Checking coordinates [4, 7]
Checking coordinates [3, 7]
Checking coordinates [3, 6]
Checking coordinates [3, 5]
Checking coordinates [4, 5]
Checking coordinates [5, 5]
Checking coordinates [6, 5]
Checking coordinates [7, 5]
Checking coordinates [8, 5]
Checking coordinates [9, 5]
Checking coordinates [9, 6]
Checking coordinates [9, 7]
Checking coordinates [9, 8]
Checking coordinates [9, 9]
Checking coordinates [10, 9]
Checking coordinates [11, 9]
Checking coordinates [11, 10]
Checking coordinates [11, 11]
Checking coordinates [12, 11]
Checking coordinates [13, 11]
Checking coordinates [14, 11]
Checking coordinates [15, 11]
Checking coordinates [13, 12]
Checking coordinates [13, 13]
Checking coordinates [13, 14]
Checking coordinates [13, 15]
Checking coordinates [12, 13]
Checking coordinates [11, 13]
Checking coordinates [11, 14]
Checking coordinates [11, 15]
Checking coordinates [10, 13]
Checking coordinates [9, 13]
Checking coordinates [9, 14]
Checking coordinates [9, 15]
Checking coordinates [8, 15]
Checking coordinates [7, 15]
Checking coordinates [7, 16]
Checking coordinates [7, 17]
Checking coordinates [7, 18]
Checking coordinates [7, 19]
Checking coordinates [8, 19]
Checking coordinates [9, 19]
Checking coordinates [10, 19]
Checking coordinates [11, 19]
Checking coordinates [12, 19]
Checking coordinates [13, 19]
Checking coordinates [14, 19]
Checking coordinates [15, 19]
Checking coordinates [9, 18]
Checking coordinates [9, 17]
Checking coordinates [10, 17]
Checking coordinates [11, 17]
Checking coordinates [12, 17]
Checking coordinates [13, 17]
Checking coordinates [14, 17]
Checking coordinates [15, 17]
Checking coordinates [16, 17]
Checking coordinates [17, 17]
Checking coordinates [18, 17]
Checking coordinates [19, 17]
Checking coordinates [19, 18]
Checking coordinates [19, 19]
Checking coordinates [18, 19]
Checking coordinates [17, 19]
Checking coordinates [17, 16]
Checking coordinates [17, 15]
Checking coordinates [18, 15]
Checking coordinates [19, 15]
Checking coordinates [16, 15]
Checking coordinates [15, 15]
Checking coordinates [15, 14]
Checking coordinates [15, 13]
Checking coordinates [16, 13]
Checking coordinates [17, 13]
Checking coordinates [18, 13]
Checking coordinates [19, 13]
Checking coordinates [19, 12]
Checking coordinates [19, 11]
Checking coordinates [18, 11]
Checking coordinates [17, 11]
Checking coordinates [17, 10]
Checking coordinates [17, 9]
Checking coordinates [16, 9]
Checking coordinates [15, 9]
Checking coordinates [14, 9]
Checking coordinates [13, 9]
Checking coordinates [13, 8]
Checking coordinates [13, 7]
Checking coordinates [12, 7]
Checking coordinates [11, 7]
Checking coordinates [11, 6]
Checking coordinates [11, 5]
Checking coordinates [11, 4]
Checking coordinates [11, 3]
Checking coordinates [12, 3]
Checking coordinates [13, 3]
Checking coordinates [13, 2]
Checking coordinates [13, 1]
Checking coordinates [12, 1]
Checking coordinates [11, 1]
Checking coordinates [10, 1]
Checking coordinates [9, 1]
Checking coordinates [8, 1]
Checking coordinates [7, 1]
Checking coordinates [6, 1]
Checking coordinates [5, 1]
Checking coordinates [4, 1]
Checking coordinates [3, 1]
Checking coordinates [3, 2]
Checking coordinates [3, 3]
Checking coordinates [2, 3]
Checking coordinates [1, 3]
Checking coordinates [1, 2]
Checking coordinates [1, 1]
Checking coordinates [19, 10]
Checking coordinates [19, 9]
Checking coordinates [19, 8]
Checking coordinates [19, 7]
Checking coordinates [18, 7]
Checking coordinates [17, 7]
Checking coordinates [16, 7]
Checking coordinates [15, 7]
Checking coordinates [15, 6]
Checking coordinates [15, 5]
Checking coordinates [14, 5]
Checking coordinates [13, 5]
Checking coordinates [15, 4]
Checking coordinates [15, 3]
Checking coordinates [16, 3]
Checking coordinates [17, 3]
Checking coordinates [17, 2]
Checking coordinates [17, 1]
Checking coordinates [18, 1]
Checking coordinates [19, 1]
Checking coordinates [19, 2]
Checking coordinates [19, 3]
Checking coordinates [19, 4]
Checking coordinates [19, 5]
Checking coordinates [18, 5]
Checking coordinates [17, 5]
Checking coordinates [16, 1]
Checking coordinates [15, 1]
Checking coordinates [9, 4]
Checking coordinates [9, 3]
Checking coordinates [8, 3]
Checking coordinates [7, 3]
Checking coordinates [6, 3]
Checking coordinates [5, 3]
Checking coordinates [3, 14]
Checking coordinates [3, 15]
Checking coordinates [2, 15]
Checking coordinates [1, 15]
Checking coordinates [1, 16]
Checking coordinates [1, 17]
Checking coordinates [2, 17]
Checking coordinates [3, 17]
Checking coordinates [4, 17]
Checking coordinates [5, 17]
Checking coordinates [5, 16]
Checking coordinates [5, 15]
Checking coordinates [1, 18]
Checking coordinates [1, 19]
Checking coordinates [2, 19]
Checking coordinates [3, 19]
Checking coordinates [4, 19]
Checking coordinates [5, 19]
Checking coordinates [5, 20]
Path found:
 [0, 13]
 [1, 13]
 [2, 13]
 [3, 13]
 [3, 14]
 [3, 15]
 [2, 15]
 [1, 15]
 [1, 16]
 [1, 17]
 [1, 18]
 [1, 19]
 [2, 19]
 [3, 19]
 [4, 19]
 [5, 19]
 [5, 20]
alex@~/0x03-pathfinding$

```

### 2. Dijkstra's - Graph
### [2-dijkstra_graph.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x03-pathfinding/2-dijkstra_graph.c)

```C
alex@~/0x03-pathfinding$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        char *city = (char *)dequeue(path);
        printf(" %s\n", city);
        free(city);
    }
    free(path);
}

/**
 * main - A simple graph to test Backtracking algorithm
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    vertex_t *start, *target;
    queue_t *path;

    graph = graph_create();
    graph_add_vertex(graph, "San Francisco", 0, 0);
    graph_add_vertex(graph, "Los Angeles", 0, 0);
    graph_add_vertex(graph, "Las Vegas", 0, 0);
    start = graph_add_vertex(graph, "Seattle", 0, 0);
    graph_add_vertex(graph, "Chicago", 0, 0);
    graph_add_vertex(graph, "Washington", 0, 0);
    graph_add_vertex(graph, "New York", 0, 0);
    graph_add_vertex(graph, "Houston", 0, 0);
    graph_add_vertex(graph, "Nashville", 0, 0);
    target = graph_add_vertex(graph, "Miami", 0, 0);
    graph_add_edge(graph, "San Francisco", "Los Angeles", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Las Vegas", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Los Angeles", "Las Vegas", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Seattle", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Seattle", "Chicago", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Chicago", "Washington", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Washington", "New York", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Las Vegas", "Houston", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Houston", "Nashville", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Washington", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Miami", 0, BIDIRECTIONAL);

    path = backtracking_graph(graph, start, target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);
    graph_delete(graph);

    return (EXIT_SUCCESS);
}
alex@~/0x03-pathfinding$ gcc -o 1-backtracking_graph -Wall -Wextra -Werror -pedantic 1-main.c 1-backtracking_graph.c -lqueues -lgraphs
alex@~/0x03-pathfinding$ ./1-backtracking_graph 
Checking Seattle
Checking San Francisco
Checking Los Angeles
Checking Las Vegas
Checking Houston
Checking Nashville
Checking Washington
Checking Chicago
Checking New York
Checking Miami
Path found:
 Seattle
 San Francisco
 Los Angeles
 Las Vegas
 Houston
 Nashville
 Miami
alex@~/0x03-pathfinding$ 

```

