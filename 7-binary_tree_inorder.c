#include "binary_trees.h"

/**
 * b__a__y_tr__e _n__rd_r - g__s thr__gh _ b__n__y tr__ _s_ng _n-_rd_r tr_v_rs_l
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ tr_v_rs_
 * @_f_nc: p__nt__r t_ _ f_nct__n t_ c_ll f_r __ch n_d_.
 * Th_ v_l__ _n th_ n_d_ m_st b_ p_ss_d _s _ p_r_m_t_r t_ th_s f_nct__n
 *
 * R__urn: v__d
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
