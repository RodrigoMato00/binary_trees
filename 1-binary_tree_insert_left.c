#include "binary_trees.h"

/**
 *binary_tree_insert_left - inserts a node as the left-child of another node
 *@parent: is a pointer to the node to insert the left-child in
 *@value:  is the value to store in the new node
 *Return: algo
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nodo_nuevo;

	if (parent == NULL)
		return (NULL);

	nodo_nuevo = malloc(sizeof(binary_tree_t));

	if (!nodo_nuevo)
		return (NULL);

	nodo_nuevo->left = parent->left;
	parent->left = nodo_nuevo;
	nodo_nuevo->parent = parent;
	nodo_nuevo->n = value;
	nodo_nuevo->right = NULL;

	if (nodo_nuevo->left)
		nodo_nuevo->left->parent = nodo_nuevo;
	return (nodo_nuevo);
}
