#include "huffman.h"

/**
 * huffman_tree - Builds the Huffman tree
 * @data: Is an array of characters of size size
 * @freq: Is an array containing the associated frequencies (of size size too)
 * @size: Size of data
 *
 * Return: A pointer to the root node of the Huffman tree, or NULL if it fails
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *heap = NULL;
	binary_tree_node_t *node = NULL;

	if (!data || !freq || !size)
		return (NULL);

	heap = huffman_priority_queue(data, freq, size);
	if (heap == NULL)
		return (NULL);

	while (heap->size > 1)
		if (!huffman_extract_and_insert(heap))
		{
			heap_delete(heap, NULL);
			return (NULL);
		}

	node = heap->root->data;
	heap_delete(heap, NULL);
	return (node);
}
