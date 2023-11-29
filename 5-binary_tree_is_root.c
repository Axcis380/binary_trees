#include "binary_trees.h"

/**
 * b__a__y_tr__e__s_r__t - ch__cks _f _ g_v_n n_d_ _s _ r__t
 * @n__e: p__nt__r t_ th_ n__e t_ ch__k
 *
 * R__urn: 1 _f n__e _s _ r__t, _nd 0 _th_rw___e. _f n__e _s NULL, r__urn 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
		return (1);
	return (0);
}
