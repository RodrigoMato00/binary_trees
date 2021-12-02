#include "binary_trees.h"

/**
 *binary_tree_rotate_right - function that performs a
 *right-rotation on a binary tree
 *@tree: is a pointer to the root node of the tree to rotate
 *Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rot;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (NULL);

	rot = tree->left;
	tree->parent = rot;
	tree->left = rot->right;

	if (rot->right)
		rot->right->parent = tree;

	rot->right = tree;
	rot->right->parent = rot;
	rot->parent = NULL;

	return (rot);
}
