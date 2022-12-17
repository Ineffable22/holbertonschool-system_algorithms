#include "heap.h"

/**
 * binary_tree_delete - Free a binarytree
 * @node: Is a pointer to binary tree
 * @free_data: Is a pointer to a function that will be used to free the content
 * of a node
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;
	binary_tree_delete(node->left, free_data);
	binary_tree_delete(node->right, free_data);
	free_data ? free(node), free_data(node->data) : free(node);
}
/**
 * heap_delete - Deallocates a heap
 * @heap: Is a pointer to the heap to delete
 * @free_data: Is a pointer to a function that will be used to free the content
 * of a node
 *
 * Return: Nothing
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	binary_tree_delete(heap->root, free_data);
	free(heap);
}
