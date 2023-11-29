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
 * b__a__y_tr__e__s_f_ll - ch__cks _f _ b__n__y tr__ _s f_ll
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ ch__k
 *
 * R__urn: 1 _f f_ll, _th_rw___ 0. _f tr__ _s NULL, r__urn 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	if (left == 0 || right == 0)
		return (0);
	return (1);
}
