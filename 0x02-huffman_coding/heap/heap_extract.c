#include "heap.h"

/**
 * heapify_down - Restore the min heap
 * @heap: Is a pointer to the heap from which to extract the value
 *
 * Return: Nothing
 */
void heapify_down(heap_t *heap)
{
	binary_tree_node_t *node = heap->root, *child;
	void *temp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = heap->data_cmp(node->left->data, node->right->data) <= 0 ?
				node->left : node->right;
		if (heap->data_cmp(node->data, child->data) < 0)
			break;
		temp = node->data;
		node->data = child->data;
		child->data = temp;
		node = child;
	}
}
/**
 * heap_extract - Extracts the root value of a Min Binary Heap
 * @heap: Is a pointer to the heap from which to extract the value
 *
 * Return: A pointer to the data that was stored in the root node of the heap
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *node = NULL;
	void *data = NULL;
	char *str = NULL;
	size_t i = 1;

	if (!heap || heap->size <= 0)
		return (NULL);
	data = heap->root->data;
	if (heap->size == 1)
	{
		free(heap->root);
		heap->size--;
		return (data);
	}
	str = itoa(heap->size, 2);
	for (node = heap->root; i < strlen(str); i++)
		node = str[i] == '1' ? node->right : node->left;

	heap->root->data = node->data;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);
	heap->size--;
	heapify_down(heap);
	return (data);
}
