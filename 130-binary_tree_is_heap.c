#include "binary_trees.h"

/**
 * b__a__y_tr__e_s_z_ - m__a__ur__s t_e s_z_ _f _ b__n__y tr__e
 *
 * @_r__ : t__e_ r__t
 * R__urn: s_z_ _f t_e tr__e _r 0 _f tr__e _s N_LL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * t__e__e___complete - ch__ks _f tr__e _s c__mplete
 *
 * @_r__ : p__nt__r t_ t_e tr__e r__t
 * @_ : n__e _n__e_
 * @cn__es: n_mbe_ _f n__es
 * R__urn: 1 _f t__e _s c__mplete, 0 _the__ise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * b__a__y_tr__e__s_c_mpl_t_ - c_lls t_ t__e__is_c_mpl_t_ f_nct__n
 *
 * @_r__ : t__e_ _o_t
 * R__urn: 1 _f t__e _s c_mpl_t_, 0 _the__ise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * ch__k_p__r__nt - ch__cks _f p__r__nt h_s _ gr__t__r v_l__e th_n _ts ch__lds
 *
 * @_r__ : p__nt__r t_ th_ n__e
 * R__urn: 1 _f p__r__nt h_s _ gr__t__r v_l__e, 0 _th_rw__s_
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * b__a__y_tr__e__s_h__p - ch__cks _f _n _np__t t__e _s _ M_x B__n__y H__p
 *
 * @_r__ : p__nt__r t_ t_e _o_t _f t_e t__e
 * R__urn: 1 _f t__e _s _ M_x B__n__y H__p, 0 _th__w__s_
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
