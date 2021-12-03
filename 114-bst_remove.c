#include "binary_trees.h"

/**
 *find_root - find the root of a Binary Search Tree
 *@node: node in a BST
 *Return: pointer to root node, else NULL
 */
bst_t *find_root(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->parent)
		node = node->parent;

	return (node);
}

/**
 *bst_search - Search for a value in a Binary Search Tree
 *@tree: pointer to root node of BST
 *@value: value to look for 9bst_t *bst_search(const bst_t *tree, int value)
 *Return: pointer to node containing value, else NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}

/**
 *bst_remove - Remove a node from a Binary Search Tree
 *The deleted node must be replaced with its first in-order successor.
 *@root: root node
 *@value: value in node to look for and remove
 *Return: pointer to new root node of tree after removing desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_root, *rep, *del;
	int stat;

	if (root == NULL)
		return (NULL);
	del = bst_search(root, value);
	if (del == NULL)
		return (NULL);
	rep = NULL, stat = 0;
	if (del->right)
	{
		rep = del->right, stat = 1;
		while (rep->left)
			rep = rep->left;
	}
	else if (del->left)
		rep = del->left;
	if (rep == NULL){
		if (del->parent->left->n == del->n)
			del->parent->left = NULL;
		else
			del->parent->right = NULL;
		new_root = find_root(del);
		free(del);
	}
	else if (stat == 1){
		del->n = rep->n;
		new_root = find_root(rep);
		if (rep->parent->left->n == rep->n)
			rep->parent->left = NULL;
		else
			rep->parent->right = NULL;
		free(rep);
	}
	else
	{
		del->n = rep->n;
		del->left = del->left->left;
		if (del->left)
			del->left->parent = del;
		new_root = find_root(del);
		free(rep);
	}
	return (new_root);
}
