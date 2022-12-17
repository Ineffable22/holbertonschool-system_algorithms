#include "heap.h"

/**
 * binary_tree_node - Creates a generic Binary Tree node
 * @parent: Is a pointer to the parent node of the node to be created
 * @data: Is the data to be stored in the node
 *
 * Return: A pointer to the created node or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new = NULL;

	new = malloc(sizeof(binary_tree_node_t));
	if (new == NULL)
	{
		fprintf(stderr, "Can't malloc\n");
		return (NULL);
	}
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}
