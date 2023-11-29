#include "binary_trees.h"

/**
 * binary_trees_ancestor finds the lowes common ancestor of two nodes
 * @first: pointer to thefirst nd
 * @second: pointr to te second node
 * Return: poiner to the lowet commonancesor node of the to given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (first == NULL || second == NULL)
		return (NULL);
	tmp = (binary_tree_t *)second;
	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
