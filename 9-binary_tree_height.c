#include "binary_trees.h"

/**
 * calc_height - recursion to get height
 * @tree: tree
 * )
 * Return: height
 */
ssize_t calc_height(const binary_tree_t *tree)
{
	ssize_t leftheight, rightheight;

	if (tree == NULL)
		return (-1);
	leftheight = calc_height(tree->left);
	rightheight = calc_height(tree->right);
	if (leftheight > rightheight)
		return (leftheight + 1);
	else
		return (rightheight + 1);
}

/**
 * binary_tree_height - calculate the height of a tree
 * @tree: pointer to tree
 * )
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);
	height = calc_height(tree);
	return (height);
}
