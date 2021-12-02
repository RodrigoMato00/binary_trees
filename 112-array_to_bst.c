#include "binary_trees.h"

/**
 *array_to_bst - function that builds a Binary Search Tree from an array
 *@array: pointer to the first element of the array to be converted
 *@size: number of element in the array
 *Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t count = 0;
	bst_t *temp;
	bst_t *temp1;

	temp = 0;
	temp1 = 0;

	if (array == NULL)
		return (NULL);

	for (count = 0; count < size; count++)
	{
		temp1 = bst_insert(&temp, array[count]);

		if (temp1 == NULL)
			continue;
	}

	return (temp);
}
