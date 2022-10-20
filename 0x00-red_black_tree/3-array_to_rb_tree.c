#include "rb_trees.h"

/**
 * array_to_rb_tree - Builds a Binary Search Tree from an array
 * @array: Is a pointer to the first element of the array to be converted
 * @size: Is the number of elements in the array
 *
 * Return: A pointer to the root node of the created R-B tree,
 * or NULL on failure. If a value in the array is already present in the tree,
 * this value must be ignored.
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *root = NULL;

	for (; size > 0; array++, size--)
		rb_tree_insert(&root, *array);
	return (root);
}
