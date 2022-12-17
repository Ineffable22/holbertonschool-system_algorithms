#include "heap.h"

/**
 * itoa - Convert a number to a specific base
 * @val: Number to convert
 * @base: Base to convert
 *
 * Return: String with number converted
 */
char *itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;

	for (; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return (&buf[i + 1]);
}

/**
 * heap_insert - Inserts a value in a Min Binary Heap
 * @heap: Is a pointer to the heap in which the node has to be inserted
 * @data: Is a pointer containing the data to store in the new node
 *
 * Return: A pointer to the created node containing data, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new = NULL, *current = NULL;
	char *str = NULL;
	size_t i = 1, *tmp = NULL;

	if (!heap || !data)
		return (NULL);
	new = binary_tree_node(new, data);
	if (new == NULL)
		return (NULL);
	heap->size++;
	if (!heap->root)
	{
		heap->root = new;
		return (new);
	}
	str = itoa(heap->size, 2);
	for (current = heap->root; i < strlen(str) - 1; i++)
		current = str[i] == '1' ? current->right : current->left;
	if (str[i] == '1')
		current->right = new;
	else
		current->left = new;
	new->parent = current;
	current = new;
	while (current->parent &&
	       heap->data_cmp(current->parent->data, current->data) > 0)
	{
		tmp = current->data;
		current->data = current->parent->data;
		current->parent->data = tmp;
		current = current->parent;
	}
	return (new);
}
