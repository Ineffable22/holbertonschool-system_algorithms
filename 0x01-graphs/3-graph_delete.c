#include "graphs.h"

/**
 * edge_delete - Completely deletes a edge
 * @edge: Edge pointer to be freed
 *
 * Return: Nothing
 */
void edge_delete(edge_t *edge)
{
	if (edge)
	{
		edge_delete(edge->next);
		free(edge);
	}
}

/**
 * vertex_delete - Completely deletes a vertex
 * @vertex: Vertex pointer to be freed
 *
 * Return: Nothing
 */
void vertex_delete(vertex_t *vertex)
{
	if (vertex)
	{
		vertex_delete(vertex->next);
		edge_delete(vertex->edges);
		if (vertex->content)
			free(vertex->content);
		free(vertex);
	}
}

/**
 * graph_delete - Completely deletes a graph
 * @graph: Graph pointer to be freed
 *
 * Return: Nothing
 */
void graph_delete(graph_t *graph)
{
	if (!graph)
		return;
	vertex_delete(graph->vertices);
	free(graph);
}
