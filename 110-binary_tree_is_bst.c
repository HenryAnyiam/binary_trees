#include "binary_trees.h"
#include <stdio.h>

void enqueue(const binary_tree_t **queue, int *last, const binary_tree_t *tree)
{
	queue[*last] = tree;
	(*last)++;
}

/**
 * binary_tree_is_bst - check if a tree is a binary search tree
 * @tree: pointer to tree
 * )
 * Return: 1 if true, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *queue[100];
	const binary_tree_t *hold, *temp = tree;
	binarry_tree_t *left[50], *right[50];
	int first = 1, last = 1, i, j, hold;

	if (tree == NULL)
		return (0);
	queue[0] = tree;
	for (i = 1; i <= 100; i++)
	{
		queue[i] = NULL;
		if (i <= 50)
		{
			left[i] = NULL;
			right[i] = NULL;
		}
	}
	while (temp)
	{
		enqueue(queue, &last, temp->left);
		enqueue(queue, &last, temp->right);
		do {
			temp = queue[first];
			first++;
		} while ((temp == NULL) && (first <= 100));
	}
	for (a = 0; a <= last; a++)
	{
		hold1 = queue[];
		while (hold)
		{
			enqueue(
	for (i = 0; i <= last; i++)
	{
		for (j = 0; j < last; j += 2)
		{
			hold = (2 * i) + j;
			if (queue[hold - 1] != NULL)
				if ((queue[i])->n < (queue[hold - 1])->n)
					return (0);
			if (queue[hold] != NULL)
				if ((queue[i])->n > (queue[hold])->n)
					return (0);
		}
	}
	return (1);
}
