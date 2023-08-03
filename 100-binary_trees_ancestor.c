#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor
 * @first: first node
 * @second: second node
 * )
 * Return: node of common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *f_hold;
	binary_tree_t *s_hold;

	if ((first == NULL) || (second == NULL))
		return (NULL);
	f_hold = first;
	s_hold = second->parent;
	while (f_hold != NULL)
	{
		while (s_hold != NULL)
		{
			if (s_hold == f_hold)
				return (s_hold);
			s_hold = s_hold->parent;
		}
		f_hold = f_hold->parent;
		s_hold = second->parent;
	}
	return (NULL);
}
