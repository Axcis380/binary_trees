#include "binary_trees.h"

/**
 * b__a__y_tr__e__s_l__f - ch__cks _f _ n_d_ _s _ l__f
 * @n__e: p__nt__r t_ th_ n__e t_ ch__k
 *
 * R__urn: 1 _f n__e _s _ l__f, _nd 0 _th_rw___e. _f n__e _s NULL, r__urn 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * b__a__y_tr__e_h__ght - m__as__r_s th_ h__ght _f _ b__n__y tr__.
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ m__as__r_ th_ h__ght _f
 *
 * R__urn: th_ h__ght _f th_ tr__. _f tr__ _s NULL, r__urn 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * b__a__y_tr__e_b_l_nc_ - m__as__r_s th_ b_l_nc_ f_ct_r _f _ b__n__y tr__.
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ m__as__r_ th_ b_l_nc_ f_ct_r _f
 *
 * D_sc__pt__n: _f tr__ _s NULL, r__urn 0
 *
 * R__urn: b_l_nc_ f_ct_r _f _ b__n__y tr__ 
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (left - right);
}
