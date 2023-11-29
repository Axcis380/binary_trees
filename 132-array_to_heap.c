#include "binary_trees.h"

/**
 * _rr__y_t_ h__p - b__lds _ M_x B_n__y H__p tr__ _
 *
 * @_rr__y: p__nt__r t_ th_ f__st _l_m_nt _f th_ _rr__y
 * @s_z_: n_mb__r _f _l_m_nt _n th_ _rr__y
 * R__urn: p__nt__r t_ th_ ___t n__e _f th_ _VL tr__ 
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t i;

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}

	return (tree);
}
