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
 * binary_tree_levelorder - traverse the tree in levelorder
 * @tree: pointer to tree
 * @func: function to print
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int first = 0, last = 0, i;
	binary_tree_t *queue[100];
	const binary_tree_t *temp = tree;

	if ((tree == NULL) || (func == NULL))
		return;
	for (i = 0; i <= 100; i++)
		queue[i] = NULL;
	while (temp)
	{
		func(temp->n);
		if (temp->left)
			enqueue(queue, &last, temp->left);
		if (temp->right)
			enqueue(queue, &last, temp->right);
		temp = queue[first];
		first++;
	}
}
