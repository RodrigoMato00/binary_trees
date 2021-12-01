#include "binary_trees.h"

/**
 *_bt_height - function that measures the height of a binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: height
 */
size_t _height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

        if (tree == NULL)
		return (0);

        left = _height(tree->left) + 1;
        right = _height(tree->right) + 1;

        if (left > right)
		return (left);
        else
		return (right);}
/**
 *_level - find a level of the binary tree
 *@tree: pointer to the root node of the tree
 *@level: the level of the tree
 *@func: a pointer to the function to level
 */
void _level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;

	else if (level == 1)
		func(tree->n);

	else
	{
		_level(tree->left, level - 1, func);
		_level(tree->right, level - 1, func);

	}
}

/**
 *binary_tree_levelorder - function that goes through a binary
 *tree using level-order traversal
 *@tree: pointer to the root node of the tree to traverse
 *@func: pointer to a function to call for each node,
 * the value in the node must be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height;
	size_t iterador;

	height = 0;
	iterador = 0;

	if (!tree)
		return;

	if (!func)
		return;

	height = _height(tree);

	for (iterador = 1; iterador <= height; iterador++)
		_level(tree, iterador, func);
}
