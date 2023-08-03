#include "binary_trees.h"

/**
 * bst_insert - insert into a binary search tree
 * @tree: pointer to tree
 * @value: value of new tree
 *)
 * Return: new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp = *tree;
	int i;

	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	if (temp == NULL)
	{
		new_node->parent = NULL;
		*tree = new_node;
		return (new_node);
	}
	while (temp)
	{
		if (value < temp->n)
		{
			i = 1;
			if (temp->left == NULL)
				break;
			temp = temp->left;
		}
		else if (value > temp->n)
		{
			i = 2;
			if (temp->right == NULL)
				break;
			temp = temp->right;
		}
		else
			return (NULL);
	}
	new_node->parent = temp;
	if (i == 1)
		temp->left = new_node;
	else
		temp->right = new_node;
	return (new_node);
}
