#include "nary_trees.h"

/**
 * nary_tree_delete - Deallocates an entire N-ary tree
 * @tree: Pointer to N-ary tree
 *
 * Return: Nothing
 */
void nary_tree_delete(nary_tree_t *tree)
{
	if (!tree)
		return;
	nary_tree_delete(tree->next);
	nary_tree_delete(tree->children);
	tree->content = (free(tree->content), NULL);
	tree = (free(tree), NULL);
}
