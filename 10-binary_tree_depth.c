#include "binary_trees.h"

/**
 * binary_tree_depth - calculate the depth of a tree
 * @tree: pointer to tree
 * )
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *hold = tree;

	if (tree == NULL)
		return (0);
	while (hold->parent != NULL)
	{
		depth++;
		hold = hold->parent;
	}
	return (depth);
}
