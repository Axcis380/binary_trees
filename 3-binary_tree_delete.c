#include "binary_trees.h"
#include <stdlib.h>

/**
 * b__a__y_tr__e_d_l_t_ - d_l_t_s _n _nt_r_ b__n__y tr__
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ tr__ t_ d_l_t_
 *
 * R__urn: v__d
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
