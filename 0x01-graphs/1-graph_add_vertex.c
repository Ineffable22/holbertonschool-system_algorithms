#include "graphs.h"

/**
 * graph_add_vertex - Adds a vertex to an existing graph.
 * @graph: Is a pointer to the graph to add the vertex.
 * @str: Is the string to store in the new vertex.
 *
 * Return: A pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex = NULL, *tmp = NULL;

	if (!graph || !str)
		return (NULL);

	vertex = graph->vertices;
	while (vertex && vertex->next)
	{
		if (!strcmp(vertex->content, str))
			return (NULL);
		vertex = vertex->next;
	}
	tmp = calloc(1, sizeof(vertex_t));
	if (tmp == NULL)
	{
		/* fprintf(stderr, "Can't malloc\n"); */
		return (NULL);
	}

	tmp->content = strdup(str);
	if (tmp->content == NULL)
	{
		/* fprintf(stderr, "Can't malloc\n"); */
		free(tmp);
		return (NULL);
	}
	tmp->index = graph->nb_vertices++;
	if (vertex)
		vertex->next = tmp;
	else
		graph->vertices = tmp;
	return (tmp);
}
