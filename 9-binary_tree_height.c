#include "binary_trees.h"

/**
 * b__a__y___r__e__e__s_l__a_f - c__e__c__s_i_ _a _o__e _s_ _ _e_f
 * @_o__e: p__n__e_ t_ t_e _o__e t_ c_e__k
 *
 * R__u__n: 1 _f _o__e _s _ _e_f, _n_ 0 _t__w___e. _f _o__e _s N___, _e__u_n: 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * b__a__y_tr__e_h__ght - m__as_r_s th_ h__ght _f _ b__n__y tr__.
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ m__as_r_ th_ h__ght _f
 *
 * R__urn: th_ h__ght _f th_ tr__. _f tr__ _s NULL, r__urn 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}
