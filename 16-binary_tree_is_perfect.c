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

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * b__a__y_tr__e__s_p_rf__t - ch__cks _f _ b__n__y tr__ _s p_rf__t
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ ch__k
 *
 * R__urn: 1 _f p_rf__t, 0 _th__w___e. _f tr__ _s NULL, r__urn 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	l = tree->left;
	r = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
