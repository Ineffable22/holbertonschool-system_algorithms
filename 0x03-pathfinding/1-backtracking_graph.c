#include "pathfinding.h"

/**
 * backtrack - Print and save content recursively with backtracking
 * @list:   List of vertex positions used to
 * @path:   Path to the vertex
 * @start:  Vertex start position
 * @target: Vertex target position
 *
 * Return: 1 if successful, otherwise 0 on failure
 */
int backtrack(char *list, queue_t *path,
	      const vertex_t *start, const vertex_t *target)
{
	edge_t *edge = NULL;
	vertex_t *vertice = NULL;
	char *content = NULL;

	if (!start)
		return (0);
	printf("Checking %s\n", start->content);
	content = strdup(start->content);
	queue_push_front(path, content);
	if (start->content == target->content)
		return (1);
	list[start->index] = 1;
	for (edge = start->edges; edge; edge = edge->next)
	{
		vertice = edge->dest;
		if (!list[vertice->index] && backtrack(list, path, vertice, target))
			return (1);
	}
	free(dequeue(path));
	return (0);
}

/**
 * backtracking_graph - Searches for the first path from a starting point to
 * a target point in a graph
 * @graph:  Is a pointer to the graph to go through
 * @start:  Is a pointer to the starting vertex
 * @target: Is a pointer to the target vertex
 *
 * Return: A queue, in which each node is a char * corresponding to a vertex,
 * forming a path from start to target
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
			    vertex_t const *target)
{
	queue_t *path = queue_create(), *transverse = queue_create();
	/*vertex_t *vertex_1 = NULL, *vertex_2 = NULL;*/
	char *list = NULL, *content = NULL;

	if (!graph || !start || !target)
		return (NULL);

	list = calloc((int)graph->nb_vertices, sizeof(char));
	if (!list || !path || !transverse)
	{
		fprintf(stderr, "Can't malloc\n");
		return (0);
	}
	if (!backtrack(list, path, start, target))
	{
		while (path->front)
			free(dequeue(path));
		free(path), free(transverse);
		path = NULL, transverse = NULL;
	}
	else
	{
		while ((content = dequeue(path)))
			queue_push_front(transverse, content);
		free(path);
	}
	free(list);
	return (transverse);
}
