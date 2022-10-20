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

/**
 * inorder_successor - finds the inorder successor of given node
 * @z: the node whose inorder successor to find
 * Return: the inorder successor
 */
rb_tree_t *inorder_successor(rb_tree_t *z)
{
	rb_tree_t *y = z->right;

	while (y && y->left)
		y = y->left;
	return (y);
}

/**
 * rb_tree_replace - replaces one node's spot with another
 * @tree: address of pointer to root of tree
 * @before: the node that was in place before
 * @after: the node in place after
 */
void rb_tree_replace(rb_tree_t **tree, rb_tree_t *before, rb_tree_t *after)
{
	if (!before->parent)
		*tree = after;
	else if (before == before->parent->left)
		before->parent->left = after;
	else
		before->parent->right = after;
	if (after)
		after->parent = before->parent;
}
