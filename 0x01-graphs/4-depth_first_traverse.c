#include "graphs.h"

int search_depth(char *list, vertex_t *vertex, int size, int depth,
		  void (*action)(const vertex_t *v, size_t depth))
{
	int bol = 0;

	if (size == 0)
		return (0);

	action(vertex, depth);
	list[vertex->index] = 1;

	if (vertex->edges && !list[(int)(vertex->edges->dest->index)])
	{
		depth = search_depth(list, vertex->edges->dest, size - 1,
				     depth + 1, action);
	}
	if (vertex->edges->next && !list[(int)vertex->edges->next->dest->index])
	{
		bol = 1;
		depth = search_depth(list, vertex->edges->next->dest, size,
				     depth + 1, action);
	}
	if (vertex->next && !list[(int)vertex->next->index])
	{
		if (bol == 1)
			search_depth(list, vertex->next, size, 1, action);
		else
			depth = search_depth(list, vertex->next, size, depth, action);
	}
	return (depth);
}

/**
 * depth_first_traveres - Goes through a graph using the depth-first algorithm.
 * @graph: Is a pointer to the graph to traverse. The traversal must start from
 * the first vertex in the vertices list.
 * @action: Is a pointer to a function to be called for each visited vertex,
 * its parameters are:
 * - v -> A const pointer to the visited vertex
 * - depth -> The depth of v, from the starting vertex
 *
 * Return: The biggest vertex depth (See example), or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	char *list = NULL;
	size_t depth = 0;

	if (!graph || !action)
		return (0);

	list = calloc((int)graph->nb_vertices, sizeof(char));
	if (list == NULL)
	{
		fprintf(stderr, "Can't malloc\n");
		return (0);
	}
	depth = search_depth(list, graph->vertices, (int)graph->nb_vertices,
			     0, action);
	return (depth);

}
