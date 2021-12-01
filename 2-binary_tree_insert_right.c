#include "binary_trees.h"

/**
 *binary_tree_insert_right - inserts a node as the right-child of another node
 *@parent: pointer to the node to insert the right-child in
 *@value: the value to store in the new node
 *Return: algo
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nodo_nuevo;

	if (parent == NULL)
		return (NULL);

	nodo_nuevo = malloc(sizeof(binary_tree_t));

	if (!nodo_nuevo)
		return (NULL);

	nodo_nuevo->right = parent->right;
	parent->right = nodo_nuevo;
	nodo_nuevo->parent = parent;
	nodo_nuevo->n = value;
	nodo_nuevo->left = NULL;

	if (nodo_nuevo->right)
		nodo_nuevo->right->parent = nodo_nuevo;
	return (nodo_nuevo);
}
