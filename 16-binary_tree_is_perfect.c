#include "binary_trees.h"

/**
 *_bt_height - function that measures the height of a binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: height
 */
size_t _bt_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l_height = _bt_height(tree->left) + 1;
	r_height = _bt_height(tree->right) + 1;

	if (l_height > r_height)
		return (l_height);

	else
		return (r_height);
}

/**
 *binary_tree_is_perfect - function that checks if a binary tree is perfect
 *@tree: is a pointer to the root node of the tree to check
 *Return: If tree is null or not perfect return 0 or otherwise return 1
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (_bt_height(tree->left) == _bt_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left)
		    && binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
}
