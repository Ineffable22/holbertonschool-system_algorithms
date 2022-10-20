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
 * rb_tree_remove_node - removes node from rb tree
 * @tree: address of pointer to root of tree
 * @z: node to remove
 */
void rb_tree_remove_node(rb_tree_t **tree, rb_tree_t *z)
{
	rb_tree_t *x, *x_parent = NULL, *y = z;
	int y_color = y->color;

	if (!z->left)
	{
		x = z->right;
		x_parent = z->parent;
		rb_tree_replace(tree, z, z->right);
	}
	else if (!z->right)
	{
		x = z->left;
		x_parent = z->parent;
		rb_tree_replace(tree, z, z->left);
	}
	else
	{
		y = inorder_successor(z);
		y_color = y->color;
		x = y->right;
		if (y->parent == z)
		{
			x ? x->parent = y : 0;
			x_parent = y;
		}
		else
		{
			rb_tree_replace(tree, y, y->right);
			x_parent = y->parent;
			y->right = z->right;
			y->right->parent = y;
		}
		rb_tree_replace(tree, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (y_color >= BLACK)
		rb_tree_remove_fixup(tree, x, x_parent);
	free(z);
}
