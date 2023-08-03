#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate a tree to the left
 * @tree: pointer to tree
 * )
 * Return: pointer to rotated tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *right = NULL, *temp;

	if (tree == NULL)
		return (NULL);
	parent = tree->parent;
	temp = tree;
	if (tree->right != NULL)
	{
		right = tree->right->left;
		temp->right->left = tree;
		temp->right->parent = parent;
		if ((parent != NULL) && (parent->right == tree))
			parent->right = tree->right;
		if ((parent != NULL) && (parent->left == tree))
			parent->left = tree->right;
	}
	temp->parent = tree->right;
	temp->right = right;
	return (temp->parent);
}
