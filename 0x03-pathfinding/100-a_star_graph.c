#include "pathfinding.h"
#include <math.h>
#define Euclidean(start) ((int)sqrt(\
			   pow((start->x - target->x), 2) + pow((start->y - target->y), 2)))

/**
 * a_start_graph - Searches for the shortest and fastest path from a starting
 *                 point to a target point in a graph
 * @graph:  Is a pointer to the graph to go through
 * @start:  Is a pointer to the starting vertex
 * @target: Is a pointer to the target vertex
 *
 * Return: A queue, in which each node is a char * corresponding to a vertex,
 *         forming a path from start to target
 */
queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
		      vertex_t const *target)
{
	queue_t *path = queue_create();
	int *dist = NULL, *coor = NULL, size = 0, idx = -1, min = INT_MAX, i = 0;
	vertex_t **v = NULL, **save = NULL, *vertice = NULL;
	edge_t *edge = NULL;

	if (!graph || !start || !target || !path)
		return (NULL);
	size = (int)graph->nb_vertices;
	save = calloc(size, sizeof(vertex_t *)), coor = calloc(size, sizeof(int));
	v = calloc(size, sizeof(vertex_t *)), dist = calloc(size, sizeof(int));
	if (!save || !coor || !dist || !v)
		return (fprintf(stderr, "Can not malloc\n"), NULL);
	for (vertice = graph->vertices; vertice; vertice = vertice->next)
		dist[vertice->index] = coor[vertice->index] = INT_MAX,
		v[vertice->index] = vertice;
	dist[start->index] = 0, save[start->index] = NULL;
	coor[start->index] = Euclidean(start);
	for (; idx != (int)target->index; coor[idx] = -1)
	{
		for (i = 0, idx = -1, min = INT_MAX; i < size; i++)
			if (coor[i] != -1 && min > coor[i])
				min = coor[i], idx = i;
		if (idx == -1)
			break;
		printf("Checking %s, distance from %s is %d\n",
		       v[idx]->content, target->content, Euclidean(v[idx]));
		for (edge = v[idx]->edges; edge; edge = edge->next)
			if (dist[edge->dest->index] != -1 &&
			    dist[edge->dest->index] > dist[idx] + edge->weight)
				dist[edge->dest->index] = dist[idx] + edge->weight,
				save[edge->dest->index] = v[idx],
				coor[edge->dest->index] = dist[edge->dest->index] + Euclidean(edge->dest);
	}
	if (idx != -1)
		for (queue_push_front(path, strdup(v[idx]->content));
		     idx != (int)start->index; idx = save[idx]->index)
			queue_push_front(path, strdup(save[idx]->content));
	else
		free(path), path = NULL;
	return (free(dist), free(coor), free(save), free(v), path);
}
