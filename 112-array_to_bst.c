#include "binary_trees.h"

/**
 * array_to_bst - from an array to a binary search tree
 * @array: array
 * @size: size of array
 *)
 * Return: Binary search tree or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
