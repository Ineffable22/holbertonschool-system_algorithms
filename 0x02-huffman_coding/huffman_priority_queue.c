#include "huffman.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int data_cmp(void *p1, void *p2)
{
	return (((symbol_t *)((binary_tree_node_t*)p1)->data)->freq
		- ((symbol_t *)((binary_tree_node_t*)p2)->data)->freq);
}

/**
 * huffman_priority_queue - Creates a priority queue for the Huffman coding
 * algorithm
 * @data: Is an array of characters of size size
 * @freq: Is an array containing the associated frequencies (of size size too)
 * @size: Size of data
 *
 * Return: A pointer to the created min heap (also called priority queue)
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap = NULL;
	size_t i = 0;
	symbol_t *symbol = NULL;
	binary_tree_node_t *node = NULL, *nested = NULL;

	if (!data || !freq || !size)
		return (NULL);

	heap = heap_create(data_cmp);
	if (heap == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		if (symbol == NULL)
		{
			heap_delete(heap, NULL);
			return (NULL);
		}
		nested = binary_tree_node(NULL, symbol);
		if (nested == NULL)
		{
			free(symbol);
			heap_delete(heap, NULL);
			return (NULL);
		}
		node = heap_insert(heap, nested);
		if (node == NULL)
		{
			free(symbol);
			free(nested);
			heap_delete(heap, NULL);
			fprintf(stderr, "Failed to insert a node\n");
			return (NULL);
		}
	}
	return (heap);
}
