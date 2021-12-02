#include "binary_trees.h"

/**
 *binary_tree_is_bst - function that checks if a binary tree is
 *a valid Binary Search Tree
 *@tree: pointer to the root node of the tree to check
 *Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int bst_right;
	int bst_left;

	if (tree == NULL)
		return (0);

	if (tree->n > tree->left->n && tree->right->n > tree->n)
		return (1);

	else
		return (0);

	bst_right = binary_tree_is_bst(tree->right);
	bst_left = binary_tree_is_bst(tree->left);

	if (bst_right == 0 && bst_left == 0)
		return (0);
}
