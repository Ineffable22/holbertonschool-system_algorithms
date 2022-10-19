#include "rb_trees.h"

/**
 * checker - Checks if a binary tree is a valid Red-Black Tree
 * @tree: Is a pointer to the root node of the tree to check
 * @color: Is the color of the node
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise and
 * If tree is NULL, return 0
 */
int checker(const rb_tree_t *tree, rb_color_t color)
{
	if (!tree)
		return (1);

	if (tree->color == RED && color == RED)
		return (0);
	if (tree->left && tree->right)
	{
		if (tree->left->color != tree->right->color)
			return (0);
		if (tree->left->n >= tree->right->n)
			return (0);
	}
	else if (tree->left || tree->right)
		return (0);

	return (checker(tree->left, tree->color == BLACK ? BLACK : RED)
		&& checker(tree->right, tree->color == BLACK ? BLACK : RED));
}

/**
 * rb_tree_is_valid - Checks if a binary tree is a valid Red-Black Tree
 * @tree: Is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise and
 * If tree is NULL, return 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree)
		return (0);

	return (checker(tree, RED));
}
