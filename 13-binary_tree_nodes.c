#include "binary_trees.h"

/**
 *binary_tree_nodes - unction that counts the nodes
 *with at least 1 child in a binary tree
 *@tree:  pointer to the root node of the tree to count the number of nodes
 *Return: number of the nodes whith at least 1 child, otherwise 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));

	else
		return (0);
}
