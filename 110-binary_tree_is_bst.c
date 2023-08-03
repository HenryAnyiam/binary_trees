#include "binary_trees.h"

/**
 * enqueue - add to queue
 * @queue: queue
 * @last: end
 * @tree: tree
 */
void enqueue(const binary_tree_t **queue, int *last, const binary_tree_t *tree)
{
	queue[*last] = tree;
	(*last)++;
}

/**
 * fill - fill queue
 * @queue: queue
 * @last: end
 * @first: start
 * @tree: tree
 */
void fill(const binary_tree_t **queue, int *last, int *first,
		const binary_tree_t *tree)
{
	const binary_tree_t *temp = tree;
	int i = 0;

	enqueue(queue, last, tree);
	(*first)++;
	while (temp)
	{
		enqueue(queue, last, temp->left);
		enqueue(queue, last, temp->right);
		do {
			temp = queue[*first];
			(*first)++;
			i++;
		} while ((temp == NULL) && (i <= 2));
	}
}

/**
 * check - compares subtrees
 * @queue: queue
 * @last: end
 * @digit: compare digit
 * @sign: < or >
 * )
 * Return: 1 or 0
 */
int check(const binary_tree_t **queue, int last, int digit, int sign)
{
	int i;

	for (i = 0; i <= last; i++)
	{
		if (queue[i] == NULL)
			continue;
		if (sign == 0)
		{
			if (digit < (queue[i])->n)
				return (0);
		}
		else
		{
			if (digit > (queue[i])->n)
				return (0);
		}
	}
	return (1);
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
	const binary_tree_t *temp = tree;
	const binary_tree_t *left[100], *right[100];
	int first = 0, last = 0, i, j, a, b = 0, c = 0, d = 0, e = 0;

	if (tree == NULL)
		return (0);
	for (i = 0; i <= 100; i++)
	{
		queue[i] = NULL;
		left[i] = NULL;
		right[i] = NULL;
	}
	fill(queue, &last, &first, temp);
	for (a = 0; a <= last; a++)
	{
		if (queue[a] != NULL)
		{
			fill(left, &c, &b, queue[a]->left);
			fill(right, &e, &d, queue[a]->right);
			i = check(left, c, (queue[a])->n, 0);
			j = check(right, e, (queue[a])->n, 1);
			if (i == 0 || j == 0)
				return (0);
			for (i = 0; i <= 50; i++)
			{
				left[i] = NULL;
				right[i] = NULL;
			}
			b = 0;
			c = 0;
			d = 0;
			e = 0;
		}
	}
	return (1);
}
