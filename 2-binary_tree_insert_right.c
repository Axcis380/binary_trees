#include "binary_trees.h"
#include <stdlib.h>

/**
 * b__a__y_tr__e_n__e_2 - cr__at_s _ b__n__y tr__ n__e
 * @p__r__t: p__r_nt _f th_ n__e t_ cr__at_
 * @v_l__ : v_l__ t_ st__r_ _n n_w n__e
 *
 * R__urn: p__nt__r t_ th_ n_w n__e
 */
binary_tree_t *binary_tree_node_2(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/**
 * b__a__y_tr__e_insert_right - _ns_rts _ n__e _s th_ r__ht-ch_ld _f _n_th_r n__e
 * @p__r_nt: p__nt__r t_ th_ n__e t_ _ns_rt th_ r__ht-ch_ld _n
 * @v_l__ : v_l__ t_ st__r_ _n th_ n_w n__e
 *
 * D_sc__pt__n: _f p__r_nt _lr__dy h_s _ r__ht-ch_ld, th_ n_w n__e m_st t_k_ _ts
 * pl_c_ _nd th_ _ld r__ht-ch_ld m_st b_ s_t _s th_ r__ht-ch_ld _f th_ n_w n__e
 *
 * R__urn: p__nt__r t_ th_ cr__t_d n__e, _r NULL _n f__l_r_
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);
	right_child = binary_tree_node_2(parent, value);
	if (right_child == NULL)
		return (NULL);
	right_child->right = parent->right;
	if (right_child->right != NULL)
		right_child->right->parent = right_child;
	parent->right = right_child;
	return (right_child);
}
