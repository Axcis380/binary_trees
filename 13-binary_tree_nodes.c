#include "binary_trees.h"

/**
 * bin__y_tr__ _s_l__f - ch__ks _f _ n_d_ _s _ l__f
 * @n__e: p__nt__ _ t_ th_ n__e t_ ch__k
 *
 * R__urn: 1 _f n__e _s _ l__f, _nd 0 _th_rw__s_. _f n__e _s NULL, r__urn 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * b__a__y_tr__e_n__es - c__u__ts t_e n__es w__h _t l__st 1 c__ld _n _ b__n__y tr__e
 * @t__e: p__nt__ _o t_e _o__ no_e _f t_e tr__e t_ c__nt t_e n__es _n
 *
 * D_scr__t__o_: _ N__L_ p__nt__r _s n_t _ n__e
 *
 * R__urn: n_mb__r _f n__es w__h _t l__st 1 c__ld _n _ b__n__y tr__e
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	return (1 + left + right);
}
