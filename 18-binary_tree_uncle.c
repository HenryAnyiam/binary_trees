#include "binary_trees.h"

/**
 * binary_tree_uncle - find the parents sibling to a node
 * @node: node to find uncle
 * )
 * Return: pointer to node or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if ((node == NULL) || (node->parent == NULL))
		return (NULL);
	parent = node->parent;
	if (parent->parent == NULL)
		return (NULL);
	if (parent == parent->parent->right)
		return (parent->parent->left);
	return (parent->parent->right);
}
