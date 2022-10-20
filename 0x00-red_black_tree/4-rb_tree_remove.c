#include "rb_trees.h"

/**
 * left_rotate - rotates subtree left
 * @tree: address of pointer to root node
 * @node: pointer to node inserted node to start fix
 */
void left_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *child = node->right;

	if (!child)
		return;
	/* printf("LEFT ROTATE:[%d]\n", node->n); */
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
 * right_rotate - rotates subtree right
 * @tree: address of pointer to root node
 * @node: pointer to node inserted node to start fix
 */
void right_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *child = node->left;

	if (!child)
		return;
	/* printf("RIGHT ROTATE:[%d]\n", node->n); */
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
 * rb_tree_remove_fix_right_sibling - fixes up RB tree properties on the right
 * @tree: address of pointer to root of tree
 * @x: the node at which to start fixup, could be null
 * @x_parent: reference to x's previous parent in case it is null
 * Return: the new x node
 */
rb_tree_t *rb_tree_fix_right_sibling(rb_tree_t **tree, rb_tree_t *x,
	rb_tree_t *x_parent)
{
	rb_tree_t *w;

	if (!x_parent)
		x_parent = x->parent;
	w = x_parent->right;
	if (w->color == RED)
	{
		w->color = BLACK;
		x_parent->color = RED;
		left_rotate(tree, x_parent);
		w = x_parent->right;
	}
	if (!w)
		return (x);
	if ((!w->left || w->left->color >= BLACK) &&
		(!w->right || w->right->color >= BLACK))
	{
		w->color = RED;
		x = x_parent;
	}
	else
	{
		if (!w->right || w->right->color >= BLACK)
		{
			w->left->color = BLACK;
			w->color = RED;
			right_rotate(tree, w);
			w = x_parent->right;
		}
		if (w)
			w->color = x_parent->color;
		x_parent->color = BLACK;
		if (w && w->right)
			w->right->color = BLACK;
		left_rotate(tree, x_parent);
		x = *tree;
	}
	return (x);
}

/**
 * rb_tree_remove_fixup_left_sibling - fixes up RB tree properties on the left
 * @tree: address of pointer to root of tree
 * @x: the node at which to start fixup, could be null
 * @x_parent: reference to x's previous parent in case it is null
 * Return: the new x node
 */
rb_tree_t *rb_tree_fix_left_sibling(rb_tree_t **tree, rb_tree_t *x,
	rb_tree_t *x_parent)
{
	rb_tree_t *w;

	if (!x_parent)
		x_parent = x->parent;
	w = x_parent->left;
	if (w->color == RED)
	{
		w->color = BLACK;
		x_parent->color = RED;
		right_rotate(tree, x_parent);
		w = x_parent->left;
	}
	if (!w)
		return (x);
	if ((!w->left || w->left->color >= BLACK) &&
		(!w->right || w->right->color >= BLACK))
	{
		w->color = RED;
		x = x_parent;
	}
	else
	{
		if (!w->left || w->left->color >= BLACK)
		{
			w->right->color = BLACK;
			w->color = RED;
			left_rotate(tree, w);
			w = x_parent->left;
		}
		if (w)
			w->color = x_parent->color;
		x_parent->color = BLACK;
		if (w && w->left)
			w->left->color = BLACK;
		right_rotate(tree, x_parent);
		x = *tree;
	}
	return (x);
}

/**
 * rb_tree_remove_fixup - fixes up RB tree properties
 * @tree: address of pointer to root of tree
 * @x: the node at which to start fixup, could be null
 * @x_parent: reference to x's previous parent in case it is null
 */
void rb_tree_remove_fixup(rb_tree_t **tree, rb_tree_t *x, rb_tree_t *x_parent)
{
	while ((x && x != *tree && x->color >= BLACK) || (!x && x_parent))
		if ((x && x == x->parent->left) || (!x && x_parent && !x_parent->left))
		{
			x = rb_tree_fix_right_sibling(tree, x, x_parent);
			x_parent = NULL;
		}
		else if ((x && x == x->parent->right) || (!x && x_parent && x_parent->left))
		{
			x = rb_tree_fix_left_sibling(tree, x, x_parent);
			x_parent = NULL;
		}
	if (x)
		x->color = BLACK;
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

/**
 * rb_tree_remove - removes node from rb tree
 * @root: pointer to root of tree
 * @n: value of node to remove
 * Return: pointer to new root of tree
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *node = root;

	while (node)
	{
		if (n > node->n)
			node = node->right;
		else if (n < node->n)
			node = node->left;
		else
			break;
	}
	if (!node)
		return (root);
	rb_tree_remove_node(&root, node);
	return (root);
}
