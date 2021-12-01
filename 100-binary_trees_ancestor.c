#include "binary_trees.h"

/**
 *binary_trees_ancestor - function that finds the lowest common
 *ancestor of two nodes
 *@first: pointer to the first node
 *@second: Pointer to the second node
 *Return: no com ancestors return null or return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *anc1;
	binary_tree_t *anc2;
	if (!first)
		return (NULL);

	if (!second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	anc1 = first->parent;
	anc2 = second->parent;

	if (first == anc2 || !anc1 || (!anc1->parent && anc2))
		return (binary_trees_ancestor(first, anc2));

	else if (anc1 == second || !anc2 || (!anc2->parent && anc1))
		return (binary_trees_ancestor(anc1, second));

	return (binary_trees_ancestor(anc1, anc2));
}
