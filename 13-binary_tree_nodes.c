#include "binary_trees.h"

/**
 * binary_tree_nodes - calculate the number of nodes with child
 * @tree: pointer to tree
 * )
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	if ((tree->right != NULL) || (tree->left != NULL))
		return (left + right + 1);
	return (left + right);
}
