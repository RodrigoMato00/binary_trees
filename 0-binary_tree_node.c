#include "binary_trees.h"

/**
 *binary_tree_node - create a binary tree node new
 *@parent: pointer to parent node
 *@value: value to put in the new node
 *Return: pointer to the new node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nuevo_nodo = malloc(sizeof(binary_tree_t));

	if (nuevo_nodo == NULL)
		return (NULL);

	nuevo_nodo->n = value;
	nuevo_nodo->parent = parent;
	nuevo_nodo->left = NULL;
	nuevo_nodo->right = NULL;
	return (nuevo_nodo);
}
