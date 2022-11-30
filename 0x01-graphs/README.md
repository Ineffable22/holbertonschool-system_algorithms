# 0x01-graphs

# Files

### 0. Create graph
### [0-graph_create.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x01-graphs/0-graph_create.c)

```C
/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
    UNIDIRECTIONAL = 0,
    BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
    vertex_t    *dest;
    struct edge_s   *next;
} edge_t;


/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 *
 * @index: Index of the vertex in the adjacency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
    size_t      index;
    char        *content;
    size_t      nb_edges;
    edge_t      *edges;
    struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjacency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjacency linked list
 */
typedef struct graph_s
{
    size_t      nb_vertices;
    vertex_t    *vertices;
} graph_t;

```

### 1. Add a vertex
### [1-graph_add_vertex.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x01-graphs/1-graph_add_vertex.c)

```C
alex@~/0x01-graphs$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    printf("Successfully created graph\n");

    return (EXIT_SUCCESS);
}
alex@~/0x01-graphs$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-graph_create.c -o 0-graph_create
alex@~/0x01-graphs$ ./0-graph_create
Successfully created graph
alex@~/0x01-graphs$

```

### 2. Add an edge
### [2-graph_add_edge.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x01-graphs/2-graph_add_edge.c)

```C
alex@~/0x01-graphs$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_vertex(graph, "San Francisco"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    if (!graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    if (!graph_add_vertex(graph, "San Francisco"))
        fprintf(stderr, "Failed to add \"San Francisco\"\n");

    return (EXIT_SUCCESS);
}
alex@~/0x01-graphs$ gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c graph_create.c 1-graph_add_vertex.c graph_display.c -o 1-graph_add_vertex
alex@~/0x01-graphs$ ./1-graph_add_vertex
Number of vertices: 1
[0] San Francisco
Number of vertices: 8
[0] San Francisco
[1] Seattle
[2] New York
[3] Miami
[4] Chicago
[5] Houston
[6] Las Vegas
[7] Boston
Failed to add "San Francisco"
alex@~/0x01-graphs$

```

### 3. Delete graph
### [3-graph_delete.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x01-graphs/3-graph_delete.c)

```C
alex@~/0x01-graphs$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_vertex(graph, "San Francisco") ||
        !graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_edge(graph, "San Francisco", "Las Vegas", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Boston", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Miami", "San Francisco", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Houston", "Seattle", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Chicago", "New York", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Las Vegas", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "New York", "Houston", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Miami", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "San Francisco", "Boston", BIDIRECTIONAL))
    {
        fprintf(stderr, "Failed to add edge\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    return (EXIT_SUCCESS);
}
alex@~/0x01-graphs$ gcc -Wall -Wextra -Werror -pedantic -g3 2-main.c graph_create.c graph_add_vertex.c 2-graph_add_edge.c graph_display.c -o 2-graph_add_edge
alex@~/0x01-graphs$ ./2-graph_add_edge
Number of vertices: 8
[0] San Francisco ->6->3->7
[1] Seattle ->4->3
[2] New York ->4->5
[3] Miami ->0->1
[4] Chicago ->2
[5] Houston ->1->2
[6] Las Vegas ->0->2
[7] Boston ->2->0
alex@~/0x01-graphs$

```

### 4. Depth-first traversal
### [4-depth_first_traverse.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x01-graphs/4-depth_first_traverse.c)

```C
alex@~/0x01-graphs$ cat 3-main.c
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_vertex(graph, "San Francisco") ||
        !graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_edge(graph, "San Francisco", "Las Vegas", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Boston", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Miami", "San Francisco", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Houston", "Seattle", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Chicago", "New York", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Las Vegas", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "New York", "Houston", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Miami", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "San Francisco", "Boston", BIDIRECTIONAL))
    {
        fprintf(stderr, "Failed to add edge\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    graph_delete(graph);

    return (EXIT_SUCCESS);
}
alex@~/0x01-graphs$ gcc -Wall -Wextra -Werror -pedantic -g3 3-main.c graph_create.c graph_add_vertex.c graph_add_edge.c 3-graph_delete.c graph_display.c -o 3-graph_delete
alex@~/0x01-graphs$ valgrind ./3-graph_delete
==9712== Memcheck, a memory error detector
==9712== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==9712== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==9712== Command: ./3-graph_delete
==9712== 
Number of vertices: 8
[0] San Francisco ->6->3->7
[1] Seattle ->4->3
[2] New York ->4->5
[3] Miami ->0->1
[4] Chicago ->2
[5] Houston ->1->2
[6] Las Vegas ->0->2
[7] Boston ->2->0
==9712== 
==9712== HEAP SUMMARY:
==9712==     in use at exit: 0 bytes in 0 blocks
==9712==   total heap usage: X allocs, X frees, Y bytes allocated
==9712== 
==9712== All heap blocks were freed -- no leaks are possible
==9712== 
==9712== For counts of detected and suppressed errors, rerun with: -v
==9712== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@~/0x01-graphs$

```

### 5. Breadth-first traversal
### [5-breadth_first_traverse.c](https://github.com/Ineffable22/holbertonschool-system_algorithms/blob/main/0x01-graphs/5-breadth_first_traverse.c)

```C
alex@~/0x01-graphs$ cat 4-main.c
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * traverse_action - Action to be executed for each visited vertex
 * during traversal
 *
 * @v: Pointer to the visited vertex
 * @depth: Depth of the vertex in graph from vertex 0
 */
void traverse_action(const vertex_t *v, size_t depth)
{
    printf("%*s[%lu] %s\n", (int)depth * 4, "", v->index, v->content);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    size_t depth;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_vertex(graph, "San Francisco") ||
        !graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_edge(graph, "San Francisco", "Las Vegas", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Boston", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Miami", "San Francisco", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Houston", "Seattle", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Chicago", "New York", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Las Vegas", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "New York", "Houston", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Miami", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "San Francisco", "Boston", BIDIRECTIONAL))
    {
        fprintf(stderr, "Failed to add edge\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    printf("\nDepth First Traversal:\n");
    depth = depth_first_traverse(graph, &traverse_action);
    printf("\nDepth: %lu\n", depth);

    graph_delete(graph);

    return (EXIT_SUCCESS);
}
alex@~/0x01-graphs$ gcc -Wall -Wextra -Werror -pedantic -g3 4-main.c graph_create.c graph_add_vertex.c graph_add_edge.c graph_delete.c 4-depth_first_traverse.c graph_display.c -o 4-depth_first_traverse
alex@~/0x01-graphs$ ./4-depth_first_traverse
Number of vertices: 8
[0] San Francisco ->6->3->7
[1] Seattle ->4->3
[2] New York ->4->5
[3] Miami ->0->1
[4] Chicago ->2
[5] Houston ->1->2
[6] Las Vegas ->0->2
[7] Boston ->2->0

Depth First Traversal:
[0] San Francisco
    [6] Las Vegas
        [2] New York
            [4] Chicago
            [5] Houston
                [1] Seattle
                    [3] Miami
    [7] Boston

Depth: 5
alex@~/0x01-graphs$

```

