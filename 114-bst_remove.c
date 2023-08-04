#include "binary_trees.h"

/**
 * search - search for a value in binary search tree
 * @tree: pointer to tree
 * @value: value to search
 *)
 * Return: node with value or NULL
 */
bst_t *search(bst_t *tree, int value)
{
        bst_t *temp = tree;

        if (tree == NULL)
                return (NULL);
        while (temp)
        {   
                if (value < temp->n)
                        temp = temp->left;
                else if (value > temp->n)
                        temp = temp->right;
                else
                        return (temp);
        }   
        return (NULL);
}
/**
 * bst_remove - remove from a binary search tree
 * @root: pointer to tree
 * @value: value
 *)
 * Return: new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *find, *parent, *rep;

	find = search(root, value);
	if (find == NULL)
		return (root);
	if (find->right == NULL && find->left == NULL)
	{
		free(find);
		return (NULL);
	}
	parent = find->parent;
	if ((find->right != NULL) && (find->left != NULL))
	{
		if (find->right->left != NULL)
		{
			rep = find->right->left;
			find->right->left = rep->right;
		}
		else
		{
			rep = find->right;
			find->right = rep->right;
		}
	}
	else
	{
		rep = find->left;
		find->left = rep->right;
	}
	rep->parent = parent;
	if ((parent != NULL) && (parent->left == find))
		parent->left = rep;
	else if ((parent != NULL) && (parent->right == find))
		parent->right = rep;
	rep->right = find->right;
	rep->left = find->left;
	if (find->left != NULL)
		find->left->parent = rep;
	if (find->right != NULL)
		find->right->parent = rep;
	free(find);
	if (parent == NULL)
		return (rep);
	else
		return (root);
}
