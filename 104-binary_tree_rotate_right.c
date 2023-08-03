#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate a tree to the right
 * @tree: pointer to tree
 * )
 * Return: rotated tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = tree, *left, *right, *parent;

	if (tree == NULL)
		return (NULL);
	parent = temp->parent;
	right = tree->left;
	if (right != NULL)
	{
		left = tree->left->right;
		temp->left->right = tree;
		temp->left->parent = parent;
		temp->left = left;
		if (left != NULL)
			left->parent = temp;
	}
	if (parent != NULL)
	{
		if (parent->right == tree)
			parent->right = right;
		else
			parent->left = right;
	}
	temp->parent = right;
	temp->left = left;
	return (temp->parent);
}
