#include "rb_trees.h"

/**
 * insert_node - Inserts a value in a node
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @value: Is the value to store in the node to be inserted
 *
 * Return: A pointer to the created node
 */
rb_tree_t *insert_node(rb_tree_t **tree, int value)
{
	rb_color_t color = RED;

	if ((*tree)->n == value)
		return (NULL);
	else if ((*tree)->n > value)
	{
		if ((*tree)->left)
		{
			if ((*tree)->color == RED && (*tree)->parent &&
			    (*tree)->parent->right && (*tree)->parent->right->color == RED)
			{
				(*tree)->color = BLACK;
				(*tree)->parent->right->color = BLACK;
			}
			return (insert_node(&(*tree)->left, value));
		}
		else /* (!(*tree)->left) */
		{
			return ((*tree)->left = rb_tree_node((*tree), value, color));

		}
	}
	else /* ((*tree)->n < value)  */
	{
		if ((*tree)->right)
			return (insert_node(&(*tree)->right, value));
		else /* ((*tree)->right) */
			return ((*tree)->right = rb_tree_node((*tree), value, color));
	}
}


/**
 * left - rotates subtree left
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @node: pointer to node inserted node to start fix
 */
void left(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *child = node->right;

	if (!child)
		return;

	node->right = child->left;
	if (child->left)
		child->left->parent = node;
	child->left = node;
	child->parent = node->parent;
	if (!node->parent)
		*tree = child;
	else if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;
	node->parent = child;
}

/**
 * right - rotates subtree right
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @node: pointer to node inserted node to start fix
 */
void right(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *child = node->left;

	if (!child)
		return;

	node->left = child->right;
	if (child->right)
		child->right->parent = node;
	child->right = node;
	child->parent = node->parent;
	if (!node->parent)
		*tree = child;
	else if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;
	node->parent = child;
}

/**
 * left_uncle - fixes RB subtree relative to left uncle
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @node: pointer to node inserted node to start fix
 * Return: pointer to inserted node
 */
rb_tree_t *left_uncle(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *uncle = node->parent->parent->left;

	if (uncle && uncle->color == RED)
	{
		uncle->color = BLACK;
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			right(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		left(tree, node->parent->parent);
	}
	return (node);
}

/**
 * right_uncle - fixes RB subtree relative to right uncle
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @node: pointer to node inserted node to start fix
 * Return: pointer to inserted node
 */
rb_tree_t *right_uncle(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *uncle = node->parent->parent->right;

	if (uncle && uncle->color == RED)
	{
		uncle->color = BLACK;
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			left(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		right(tree, node->parent->parent);
	}
	return (node);
}

/**
 * rb_tree_insert_fix - fixes RB Tree properties after insert
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @node: pointer to node inserted node to start fix
 * Return: pointer to inserted node
 */
rb_tree_t *rb_tree_insert_fix(rb_tree_t **tree, rb_tree_t *node)
{
	while (node->parent && node->parent->color == RED)
	{
		if (node->parent->parent->left == node->parent)
		{
			node = right_uncle(tree, node);
		}
		else
		{
			node = left_uncle(tree, node);
		}
	}
	(*tree)->color = BLACK;
	return (node);
}

/**
 * rb_tree_insert - Inserts a value in a Red-Black Tree
 * @tree: Is a double pointer to the root node of the Red-Black
 * tree to insert the value
 * @value: Is the value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must
 * become the root node.
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node = NULL;

	if (!tree || !(*tree))
		return (*tree = rb_tree_node((*tree), value, BLACK));

	node = insert_node(tree, value);
	if (node == NULL)
		return (NULL);
	rb_tree_insert_fix(tree, node);
	return (node);
}

