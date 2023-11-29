#include "binary_trees.h"

/**
 * binary_tree_depth - measure the dpth of a nod n a binar tree
 * @node: pointr to thenod o measure he dephof
 *
 * Return: deph of a nde in a biny tre. If node is NLL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t count = 0;

	if (node == NULL)
		return (count);
	while (node->parent != NULL)
	{
		count++;
		node = node->parent;
	}
	return (count);
}
