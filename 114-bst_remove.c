#include "binary_trees.h"

/**
 *_minimum - find the leftmost leaf
 *@node: pointer to the root node of the tree will remove a node.
 *Return: pointer to the leftmost leaf.
 */
bst_t *_minimum(bst_t *node)
{
	bst_t *pos = node;

	while (pos && pos->left != NULL)
		pos = pos->left;

	return (pos);
}

/**
 *bst_remove - function that removes a node from a Binary Search Tree
 *@root: pointer to the root node of the tree where you will remove a node
 *@value: value to remove in the tree
 *Return: pointer to the new root node of the tree
 *after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	temp = 0;
	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}

		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = _minimum(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
