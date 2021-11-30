#include "binary_trees.h"

/**
 *binary_tree_height - function that measures the height of a binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t s_left;
	size_t s_right;

	s_left = 0;
	s_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		s_left = 1 + binary_tree_height(tree->left);

	if (tree->right)
		s_right = 1 + binary_tree_height(tree->right);

	if (s_left >= s_right)
		return (s_left);

	else
		return (s_right);
}
