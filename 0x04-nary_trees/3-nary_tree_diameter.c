#include "nary_trees.h"

/**
 * compute_diameter - Compute the maximun distance between two nodes
 * @root: the root node
 * @diameter: the distance between two nodes
 *
 * Return: The maximum value between children and the next nodes
 */
size_t compute_diameter(const nary_tree_t *root, size_t *diameter)
{
	size_t max_height1 = 0, max_height2 = 0, height = 0;
	const nary_tree_t *child = NULL;

	if (!root)
		return (0);

	for (child = root->children; child; child = child->next)
	{
		height = compute_diameter(child, diameter);
		if (height > max_height1)
		{
			max_height2 = max_height1;
			max_height1 = height;
		}
		else if (height > max_height2)
			max_height2 = height;
	}
	*diameter = MAX(*diameter, max_height1 + max_height2);
	return (MAX(max_height1, max_height2) + 1);
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

	!root ? diameter-- : compute_diameter(root, &diameter);
	return (diameter + 1);
}
