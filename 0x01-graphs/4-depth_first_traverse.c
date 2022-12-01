#include "graphs.h"

/**
 * search_depth - Search depth
 * @list: Array with 0s
 * @depth: Depth number
 * @vertex: A pointer to vertex
 * @action: Is a pointer to a function to be called for each visited vertex,
 * its parameters are:
 * - v -> A const pointer to the visited vertex
 * - depth -> The depth of v, from the starting vertex
 *
 * Return: Depth
 */
int search_depth(char *list, vertex_t *vertex, int depth,
		  void (*action)(const vertex_t *v, size_t depth))
{
	int max = 0, dt = 0;

	if (!vertex)
		return (0);
	action(vertex, depth);
	list[vertex->index] = 1;
	max = depth;
	for (; vertex->edges; vertex->edges = vertex->edges->next)
	{
		if (!list[vertex->edges->dest->index])
		{
			dt = search_depth(list, vertex->edges->dest, depth + 1, action);
			max = max > dt ? max : dt;
		}
	}
	return (max);
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
	depth = search_depth(list, graph->vertices, 0, action);
	free(list);
	return (depth);

}
