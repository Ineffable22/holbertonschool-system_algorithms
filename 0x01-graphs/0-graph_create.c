#include "graphs.h"


/**
 * graph_create - Allocates memory to store a graph_t structure,
 * and initializes its content.
 *
 * Return: A pointer to the allocated structure, or NULL on failure.
 */
graph_t *graph_create(void)
{
	graph_t *new_graph = NULL;

	new_graph = malloc(sizeof(graph_t));
	if (new_graph == NULL)
	{
		fprintf(stderr, "Can't malloc\n");
		return (NULL);
	}
	new_graph->nb_vertices = 0;
	new_graph->vertices = NULL;
	return (new_graph);
}
