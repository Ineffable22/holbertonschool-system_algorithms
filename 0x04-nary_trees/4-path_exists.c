#include "nary_trees.h"

/**
 * path_exists - Checks if a path exists in an N-ary tree
 * @root: Is a pointer to the root node of the tree
 * @path: Is a NULL terminated array of strings
 *
 * Return: 1 if all the elements of path are present in the tree and if for
 * an element of path at the index i is present in one of the nodes at the
 * depth i. And of course, all the nodes must be linked to form a path.
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	if (!root && (*path || !path))
		return (0);
	if (!*path)
		return (1);
	if (!strcmp(root->content, *path))
		return (path_exists(root->children, path + 1));
	return (path_exists(root->next, path));
}
