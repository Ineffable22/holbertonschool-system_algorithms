#include "pathfinding.h"

/**
 * dijkstra_graph - Searches for the shortest path from a starting point
 *                  to a target point in a graph
 * @graph:  Is a pointer to the graph to go through
 * @start:  Is a pointer to the starting vertex
 * @target: Is a pointer to the target vertex
 *
 * Return:  A queue, in which each node is a char * corresponding to a vertex,
 *          forming a path from start to target
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
			vertex_t const *target)
{
	queue_t *path = queue_create();
	int *dist = NULL, size = 0, idx = -1, min = INT_MAX, i = 0;
	vertex_t **v = NULL, **save = NULL, *vertice = NULL;
	edge_t *edge = NULL;

	if (!graph || !start || !target || !path)
		return (NULL);
	size = (int)graph->nb_vertices;
	dist = calloc(size, sizeof(int));
	save = calloc(size, sizeof(vertex_t *));
	v = calloc(size, sizeof(vertex_t *));
	if (!save || !dist || !v)
		return (fprintf(stderr, "Can not malloc\n"), NULL);
	for (vertice = graph->vertices; vertice; vertice = vertice->next)
		dist[vertice->index] = INT_MAX, v[vertice->index] = vertice;
	for (dist[start->index] = 0, save[start->index] = NULL;
	     idx != (int)target->index;)
	{
		for (i = 0, idx = -1, min = INT_MAX; i < size; i++)
			if (dist[i] != -1 && min > dist[i])
				min = dist[i], idx = i;
		if (idx == -1)
			break;
		printf("Checking %s, distance from %s is %d\n",
		       v[idx]->content, start->content, dist[idx]);
		for (edge = v[idx]->edges; edge; edge = edge->next)
			if (dist[edge->dest->index] != -1 && dist[edge->dest->index] > dist[idx] + edge->weight)
				dist[edge->dest->index] = dist[idx] + edge->weight,
					save[edge->dest->index] = v[idx];
		dist[idx] = -1;
	}
	if (idx != -1)
		for (queue_push_front(path, strdup(v[idx]->content));
		     idx != (int)start->index; idx = save[idx]->index)
			queue_push_front(path, strdup(save[idx]->content));
	else
		free(path), path = NULL;
	free(dist), free(save), free(v);
	return (path);
}
