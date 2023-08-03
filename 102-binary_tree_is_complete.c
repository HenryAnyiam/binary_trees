#include "binary_trees.h"

/**
 * enqueue - add to queue
 * @queue: pointer to queue array
 * @last: end of queue
 * @tree: ponter to tree
 */
void enqueue(binary_tree_t **queue, int *last, binary_tree_t *tree)
{
	queue[*last] = tree;
	(*last)++;
}


/**
 * binary_tree_is_complete - checks if tree is complete
 * @tree: pointer to tree
 * )
 * Return: 1 if complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int first = 0, last = 0, check = 0;
	binary_tree_t **queue;
	const binary_tree_t *temp = tree;

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t) * 100);
	if ((tree == NULL) || (queue == NULL))
		return (0);
	enqueue(queue, &last, temp->left);
	enqueue(queue, &last, temp->right);
	while (first < last)
	{
		temp = queue[first];
		first++;
		if (temp)
		{
			if (check == 1)
			{
				free(queue);
				return (0);
			}
			enqueue(queue, &last, temp->left);
			enqueue(queue, &last, temp->right);
		}
		else
			check = 1;
	}
	free(queue);
	return (1);
}
