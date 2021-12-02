#include "binary_trees.h"

/**
 *_bst - check the tree is bst
 *@tree: tree to checked
 *@low: minimum value
 *@hight: maximum value
 *Return: 1 it is or 0 is not
 */

int _bst(const binary_tree_t *tree, int low, int hight)
{
	if (tree == NULL)
		return (1);

	if (tree->n < low || tree->n > hight)
		return (0);

	return (_bst(tree->left, low, tree->n - 1) && _bst(tree->right, tree->n + 1, hight));
}

/**
 *binary_tree_is_bst - function that checks if a binary tree is
 *a valid Binary Search Tree
 *@tree: pointer to the root node of the tree to check
 *Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_bst(tree, INT_MIN, INT_MAX));
}
