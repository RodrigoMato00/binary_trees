#include "binary_trees.h"

/**
 * height - find Measures the height of a binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: tree is NULL function must return 0 or return height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lleft = 0;
	        size_t rright = 0;

		lleft = tree->left ? 1 + height(tree->left) : 1;
		rright = tree->right ? 1 + height(tree->right) : 1;

		return ((lleft > rright) ? lleft : rright);
	}
	return (0);
}

/**
 *is_avl_helper - Checks if a binary tree is a valid AVL tree
 *@tree: pointer to the root node of the tree to check
 *@lo: value of the smallest node visited thus far
 *@hi: value of the largest node visited this far
 *Return: tree is a valid AVL tree, 1, otherwise, 0
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lh;
	size_t rh;
	size_t dif;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);

		lh = height(tree->left);
		rh = height(tree->right);
		dif = lh > rh ? lh - rh : rh - lh;

		if (dif > 1)
			return (0);

		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 *binary_tree_is_avl - function that checks if a binary tree is a valid AVL Tree
 *@tree: pointer to the root node of the tree to check
 *Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)

		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
