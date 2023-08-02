#include "binary_trees.h"

/**
 * check_tree - checks a trees height
 * @tree: pointer to tree
 * )
 * Return: height
 */
int check_tree(const binary_tree_t *tree)
{
	int left, right, check;

	if (tree == NULL)
		return (-1);
	left = check_tree(tree->left);
	right = check_tree(tree->right);
	if (left > right)
		return (left + 1);
	check = binary_tree_is_perfect(tree);
	if (check == 0)
		return (left + right + 1);
	return (right + 1);
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: pointer to tree
 * )
 * Return: 1 if perfect else
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = check_tree(tree->left);
	right = check_tree(tree->right);
	if (left == right)
		return (1);
	return (0);
}
