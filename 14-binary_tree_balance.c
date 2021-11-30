#include "binary_trees.h"

/**
 *_bt_height - blablablabla
 *@tree: blablablablabla
 *Return: blablablablabla
 */
int _bt_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = _bt_height(tree->left) + 1;
	right = _bt_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 *binary_tree_balance - function that measures
 *the balance factor of a binary tree
 *@tree: pointer to the root node of the tree to measure the balance factor
 *Return: balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (tree == NULL)
		return (0);

	balance = _bt_height(tree->left) - _bt_height(tree->right);

	return (balance);
}
