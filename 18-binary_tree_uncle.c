#include "binary_trees.h"

/**
 * b__a__y_tr__e_ncle - f__nds th_ _ncl_ _f _ n_d_
 * @n__e: p__nt__r t_ th_ n__e t_ f__nd th_ _ncl_ _f
 *
 * R__urn: p__nt__r t_ th_ _ncl_ n__e, _r NULL _f n_ _ncl_
 */ 
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
