#include "binary_trees.h"

/**
 * full_tree - finds full tree
 * @tree: pointer to tree
 * )
 * Return: 0 if full, else some other number
 */
int full_tree(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = full_tree(tree->left);
	right = full_tree(tree->right);
	if ((tree->left == NULL) && (tree->right == NULL))
		return (left + right);
	if ((tree->left != NULL) && (tree->right != NULL))
		return (left + right);
	return (left + right + 1);
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to tree
 * )
 * Return: 1 if full, else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full;

	if (tree == NULL)
		return (0);
	full = full_tree(tree);
	if (full == 0)
		return (1);
	return (0);
}
