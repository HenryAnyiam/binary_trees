#include "binary_trees.h"

/**
 * binary_tree_leaves - calculate the number of leaves in a tree
 * @tree: pointer to tree
 * )
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	if ((tree->right == NULL) && (tree->left == NULL))
		return (1);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return (left + right);
}
