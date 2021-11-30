#include "binary_trees.h"

/**
 *binary_tree_depth - function that measures the depth
 *of a node in a binary tree
 *@tree:  pointer to the node to measure the depth
 *Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t temp;

	temp = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent)
		temp = 1 + binary_tree_depth(tree->parent);
	return (temp);
}
