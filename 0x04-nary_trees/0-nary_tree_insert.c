#include "nary_trees.h"

/**
 * nary_tree_insert - Inserts a node in a N-ary tree
 * @parent: Is a pointer to the parent node
 * @str:    Is the string to be stored in the created node.
 *          It must be duplicated
 *
 * Return: A pointer to the created node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *node = NULL;

	if (!str)
		return (NULL);
	node = calloc(1, sizeof(nary_tree_t));
	if (!node)
		return (NULL);
	node->content = strdup(str);
	if (!(node->content))
		return (free(node), NULL);
	if (!parent)
		return (node);
	node->next = parent->children;
	parent->children = node;
	parent->nb_children++;
	return (node);
}
