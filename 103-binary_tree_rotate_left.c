#include "binary_trees.h"

/**
 *binary_tree_rotate_left - function that performs a
 *left-rotation on a binary tree
 *@tree: is a pointer to the root node of the tree to rotate
 *Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rot;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (NULL);

	rot = tree->right;
	tree->parent = rot;
	tree->right = rot->left;

	if (rot->left)
		rot->left->parent = tree;

	rot->left = tree;
	rot->left->parent = rot;
	rot->parent = NULL;

	return (rot);
}
