#include "heap.h"

/**
 * heap_create - Creates a Heap data structure
 * @data_cmp: Is a pointer to a comparison function
 * - This function takes two void * parameters, each one being the data stored
 * in a node.
 * - This function will return the difference between the two data stored at
 * those pointers.
 * - It will be used to determine if a node’s value is greater or lower than
 * another, so we can build our heap
 *
 * Return: A pointer to the created heap_t structure, or NULL if it fails
 * root must be set to NULL
 * size must be set to 0
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new = NULL;

	new = malloc(sizeof(heap_t));
	if (new == NULL)
	{
		fprintf(stderr, "Can't malloc\n");
		return (NULL);
	}
	new->size = 0;
	new->data_cmp = data_cmp;
	new->root = NULL;
	return (new);
}
