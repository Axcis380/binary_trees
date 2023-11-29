#include "binary_trees.h"

/**
 * b__a__y_tr__e_s_bl_ng - f_nds th_ s_bl_ng _f _ n_d_
 * @n_d_: p__nt__r t_ th_ n_d_ t_ f_nd th_ s_bl_ng _f
 *
 * R__urn: p__nt__r t_ th_ s_bl_ng n_d_, _r NULL _f n_ s_bl_ng
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
