#include "huffman.h"

/**
 * huffman_extract_and_insert - Extracts the two nodes of the priority queue
 * and insert a new one
 * @priority_queue: Is a pointer to the priority queue to extract
 *
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node1 = NULL, *node2 = NULL;
	binary_tree_node_t *node = NULL, *nested = NULL;
	size_t freq = 0;
	symbol_t *symbol = NULL;

	if (!priority_queue)
		return (0);

	node1 = heap_extract(priority_queue);
	node2 = heap_extract(priority_queue);
	freq = ((symbol_t *)(node1->data))->freq +
		((symbol_t *)(node2->data))->freq;
	symbol = symbol_create(-1, freq);
	if (symbol == NULL)
		return (heap_delete(priority_queue, NULL), 0);
	nested = binary_tree_node(NULL, symbol);
	if (nested == NULL)
		return (heap_delete(priority_queue, NULL), free(symbol), 0);
	node = heap_insert(priority_queue, nested);
	if (node == NULL)
		return (heap_delete(priority_queue, NULL), free(symbol),
			free(nested), 0);
	return (1);
}
