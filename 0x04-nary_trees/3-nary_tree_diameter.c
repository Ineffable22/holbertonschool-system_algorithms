#include "nary_trees.h"

/**
 * compute_diameter - Compute the maximun distance between two nodes
 * @root: the root node
 * @diameter: the distance between two nodes
 *
 * Return: The maximum value between children and the next nodes
 */
size_t compute_diameter(nary_tree_t const *root, size_t *diameter)
{
	size_t a = 0, b = 0;

	if (!root)
		return (0);
	a = compute_diameter(root->children,  &(*diameter));
	b = compute_diameter(root->next, &(*diameter));
	(*diameter) = a + b;
	return (MAX(a, b) + 1);
}

/**
 * nary_tree_diameter - Computes the diameter of an N-ary tree
 * @root: Is a pointer to the root node of the tree to compute the diameter
 *
 * Return: The diameter of the tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;

	compute_diameter(root, &diameter);
	return (root ? diameter - 1 : 0);
}
