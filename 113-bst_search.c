#include "binary_trees.h"

/**
 * bst_search - search for a value in binary search tree
 * @tree: pointer to tree
 * @value: value to search
 *)
 * Return: node with value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *temp = tree;

	if (tree == NULL)
		return (NULL);
	while (temp)
	{
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else
			return ((bst_t *)temp);
	}
	return (NULL);
}
