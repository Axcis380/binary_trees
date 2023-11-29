#include "binary_trees.h"

/**
 * tr__e_s_z_ - m__as__res th_ s_m _f h__ghts _f _ b__n__y tr__e
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th tre t m_as_re th_ h_ght
 *
 * R__urn: H__ght _r 0 _f tr__e _s N_LL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * h__p_t_ s_rt_d _rr_y - c_nv_rts _ B_n__y M_x H__p
 * t_ _ s_rt_d _rr_y _f _nt_g_rs
 *
 * @_h__p: p__nt__r t_ th_ r__t n__e _f th_ h__p t_ c_nv_rt
 * @_s_z_: _dd__ss t_ st__r_ th_ s_z_ _f th_ _rr_y
 *
 * R__urn: p__nt__r t_ _rr_y s_rt_d _n d_sc_nd_ng _rd_r
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
