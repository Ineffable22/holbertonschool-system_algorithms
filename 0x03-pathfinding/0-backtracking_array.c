#include "pathfinding.h"

/**
 * print_map - Print the map with other symbols and coordinates
 * @map:  Is the pointer to a read-only two-dimensional array
 *        - A 0 represents a walkable cell
 *        - A 1 represents a blocked cell
 * @rows: Rows of map
 * @cols: Columns of map
 *
 * Return: Notthing
 */
void print_map(char **map, int rows, int cols)
{
	int x = 0, y = 0;

	printf("    ");
	for (y = 0; y < cols; y++)
	{
		if (x == 0)
			printf("%02d|", y);
	}
	putchar(0xA);

	for (x = 0; x < rows; x++)
	{
		printf("%02d| ", x);
		for (y = 0; y < cols; y++)
			if (map[x][y] == '1')
				printf("(=)");
			else if (map[x][y] == '0')
				printf("...");
			else
				printf("XXX");
		putchar(0xA);
	}
}

/**
 * backtrack - Print and save coordinates recursively with backtracking
 * @map:    Is the pointer to map
 *          - A 0 represents a walkable cell
 *          - A 1 represents a blocked cell
 * @rows:   Rows of map
 * @cols:   Columns of map
 * @x:      x-coordinate
 * @y:      y-coordinate
 * @target: Stores the coordinates of the target point
 * @queue:  Pointer to queue of struct queue_t
 *
 * Return: 1 if successful, otherwise 0 on failure
*/
int backtrack(char **map, int rows, int cols,
			    int x, int y, point_t const *target,
			    queue_t *queue)
{
	point_t *ptr = NULL;

	if (x < 0 || y < 0 || x >= rows || y >= cols || map[y][x] != '0')
		return (0);

	map[y][x] = '1';
	/* PRINT MAP */
	/* if (map[y][x] == 'X')*/
	/*	return (0);*/
	/* map[y][x] = 'X'; */
	/* print_map(map, rows, cols); */

	ptr = calloc(1, sizeof(point_t));
	if (!ptr)
	{
		fprintf(stderr, "Can not malloc\n");
		return (0);
	}
	printf("Checking coordinates [%d, %d]\n", x, y);
	ptr->x = x, ptr->y = y;
	queue_push_front(queue, ptr);
	if (target->x == x && target->y == y)
		return (1);

	if (backtrack(map, rows, cols, x + 1, y, target, queue) ||
	    backtrack(map, rows, cols, x, y + 1, target, queue) ||
	    backtrack(map, rows, cols, x - 1, y, target, queue) ||
	    backtrack(map, rows, cols, x, y - 1, target, queue))
		return (1);
	free(dequeue(queue));
	return (0);
}


/**
 * copy_map - Copy map to new_map
 * @new_map: Pointer to save new map
 * @map:     Is the pointer to map
 *           - A 0 represents a walkable cell
 *           - A 1 represents a blocked cell
 * @rows:    Rows of map
 * @cols:    Columns of map
 *
 * Return: Pointer to new map
 */
char **copy_map(char **new_map, char **map, int rows, int cols)
{
	int i = 0;

	new_map = calloc(rows, sizeof(char *));
	if (!new_map)
	{
		fprintf(stderr, "Can not malloc\n");
		return (NULL);
	}
	for (i = 0; i < rows; i++)
	{
		new_map[i] = calloc(cols + 1, sizeof(char));
		if (!new_map[i])
		{
			for (i--; i >= 0; i--)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
		strncpy(new_map[i], map[i], cols);
	}
	return (new_map);
}

/**
 * backtracking_array - Searches for the first path from a starting point
 * to a target point within a two-dimensional array
 * @map:    Is the pointer to a read-only two-dimensional array
 *          - A 0 represents a walkable cell
 *          - A 1 represents a blocked cell
 * @rows:   Rows of map
 * @cols:   Columns of map
 * @start:  Stores the coordinates of the starting point
 * @target: Stores the coordinates of the target point
 *
 * Return: A queue, in which each node is a point in the path from
 * start to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target)
{
	queue_t *queue = NULL, *back_queue = NULL;
	char **new_map = NULL;
	point_t *ptr = NULL;
	int i = 0;

	if (!map || !rows || !cols || !start || !target)
		return (NULL);
	queue = queue_create(), back_queue = queue_create();
	if (!queue || !back_queue)
	{
		fprintf(stderr, "Can not malloc\n");
		return (NULL);
	}
	/* PRINT MAP */
	/* print_map(map, rows, cols); */
	new_map = copy_map(new_map, map, rows, cols);
	if (!new_map)
	{
		free(queue);
		fprintf(stderr, "Can not malloc\n");
		return (NULL);
	}
	if (!backtrack(new_map, rows, cols, start->x, start->y, target, queue))
	{
		while (queue->front)
			free(dequeue(queue));
		queue_delete(queue), queue_delete(back_queue);
		queue = NULL, back_queue = NULL;
	}
	else
	{
		while ((ptr = dequeue(queue)))
			queue_push_front(back_queue, ptr);
		free(queue);
	}
	for (i = 0; i < rows; i++)
		free(new_map[i]);
	free(new_map);

	return (back_queue);
}
