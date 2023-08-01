#include "binary_trees.h"

/**
 * find_height - find the height of a tree
 * @tree: pointer to tree
 * )
 * Return: height of tree
 */
int find_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);
	left = find_height(tree->left);
	right = find_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
/**
 * binary_tree_balance - calculate the balanced factor of a tree
 * @tree: pointer to tree
 * )
 * Return: balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = find_height(tree->left);
	right = find_height(tree->right);
	return (left - right);
}
