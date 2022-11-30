#include "graphs.h"

/**
 * find_edge - Find edge
 * @vertex: A pointer to vertex
 * @src: String to find.
 *
 * Return: A pointer vertex, otherwise NULL
 */
vertex_t *find_edge(vertex_t *vertex, const char *src)
{
	for (; vertex; vertex = vertex->next)
		if (!strcmp(vertex->content, src))
			return (vertex);
	return (NULL);
}

/**
 * add_edge - Adds a edge to an existing vertex.
 * @src: vertex source
 * @dest: vertex destination
 *
 * Return: A edge pointer
 */
edge_t *add_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *edge = NULL, *tmp = NULL;

	if (!src || !dest)
		return (NULL);
	edge = malloc(sizeof(edge_t));
	if (!edge)
		return (NULL);
	edge->dest = dest;
	edge->next = NULL;
	tmp = src->edges;
	while (tmp && tmp->next)
		tmp = tmp->next;
	src->nb_edges++;
	if (tmp)
		tmp->next = edge;
	else
		src->edges = edge;
	return (edge);
}

/**
 * graph_add_edge - Adds an edge between two vertices to an existing graph.
 * @graph: Is a pointer to the graph to add the edge.
 * @src: Is the string identifying the vertex to make the connection.
 * @dest: Is the string identifying the vertex to connect.
 * @type: Is the type of edge.
 * - UNIDIRECTIONAL: Only one edge is created connecting src to dest
 * - BIDIRECTIONAL: Two edges are created, connecting src to dest AND
 * dest to src.
 *
 * Return: 1 on success, or 0 on failure. On failure, no edge must have be
 * created, and there must be no memory leak.
 */
int graph_add_edge(graph_t *graph, const char *src,
		   const char *dest, edge_type_t type)
{
	vertex_t *v_src = NULL, *v_dest = NULL;

	if (!graph || !src || !dest)
		return (0);
	v_src = find_edge(graph->vertices, src);
	v_dest = find_edge(graph->vertices, dest);
	if (!v_src || !v_dest || !add_edge(v_src, v_dest) ||
	    (type == BIDIRECTIONAL && !add_edge(v_dest, v_src)))
		return (0);
	return (1);
}
