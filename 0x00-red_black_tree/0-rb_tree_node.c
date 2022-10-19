#include "rb_trees.h"

/**
 * rb_tree_node - Creates a Red-Black Tree node
 * @parent: Is a pointer to the parent node of the node to create
 * @value: Is the value to put in the new node
 * @color: Is the color of the node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *node = NULL;

	node = malloc(sizeof(rb_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->color = color;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
