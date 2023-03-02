#include "nary_trees.h"

/**
 * _nary_tree_traverse - Goes through an N-ary tree, node by node
 * @root:   Is a pointer to the root node of the tree to traverse
 * @action: Is a pointer to a function to execute for each node being traversed
 *          Its arguments are:
 *          - @node: Is a pointer to the node being traversed
 *          - @depth: Is the depth of the node being traversed
 * @dp:     Current node depth
 *
 * Return: The biggest depth of the tree pointed to by root
 */
size_t _nary_tree_traverse(nary_tree_t const *root,
			 void (*action)(nary_tree_t const *node, size_t depth), int dp)
{
	int max = dp, ret_depth = 0;

	if (!root)
		return (dp);
	action(root, dp);
	ret_depth = _nary_tree_traverse(root->children, action, dp + 1);
	_nary_tree_traverse(root->next, action, dp);
	return (MAX(max, ret_depth));
}

/**
 * nary_tree_traverse - Goes through an N-ary tree, node by node
 * @root:   Is a pointer to the root node of the tree to traverse
 * @action: Is a pointer to a function to execute for each node being traversed
 *          Its arguments are:
 *          - @node: Is a pointer to the node being traversed
 *          - @depth: Is the depth of the node being traversed
 *
 * Return: The biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
			 void (*action)(nary_tree_t const *node, size_t depth))
{
	if (!root || !action)
		return (0);
	return (_nary_tree_traverse(root, action, 0));
}
