#include "binary_trees.h"

/**
 *bst_insert - function that inserts a value in a Binary Search Tree
 *@tree: double pointer to the root node of the BST to insert the value
 *@value: value to store in the node to be inserted
 *Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree != NULL)
	{
		if (*tree == NULL)
		{
			(*tree) = binary_tree_node(*tree, value);
			/* binary_tree_node is the task 0, this function that*/
/*creates a binary tree node */
			return (*tree);
		}
		if (value == (*tree)->n)
			return (NULL);

		if (value < (*tree)->n)
		{
			if ((*tree)->left == NULL)
			{
				(*tree)->left = binary_tree_node(*tree, value);
				return ((*tree)->left);
			}

			else
				return (bst_insert(&((*tree)->left), value));
		}

		else
		{

			if ((*tree)->right == NULL)
			{
				(*tree)->right = binary_tree_node(*tree, value);
				return ((*tree)->right);
			}

			else
				return (bst_insert(&((*tree)->right), value));
		}
	}
	return (NULL);
}