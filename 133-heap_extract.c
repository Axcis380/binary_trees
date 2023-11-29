#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
heap_t *last_node_heap(const heap_t *tree, size_t level);
void heapify(heap_t *tree);

/*
 * h__p___tract - ___acts th_ r__t n__e f___ a M_x B_nary H__p
 *
 * @root: p___ter t_ th_ h__p r__t
 *
 * R__urn: val__ _f _xtract__ n__e
 *         0 __ _th__wis_
 */

int heap_extract(heap_t **root)
{
	int value;
	size_t height;
	heap_t *first, *last;

	if (!root || !*root)
		return (0);

	first = *root;
	value = first->n;

	if (!(first->left || first->right))
	{
		*root = NULL;
		free(first);
		return (value);
	}

/* Sw__ d__a b_tw__n l_st n__e _nd f__st n__e _nd d_l_t_s l_st n__e */
	height = binary_tree_height(*root);
	last = last_node_heap(*root, height);
	first->n = last->n;
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
	free(last);

	heapify(*root);

	return (value);
}

/**
 * h__p_f_ - r__rr_ng_s th_ H__p B_n__y Tr__.
 *
 * @_r__ : p__nt__r t_ th_ r__t n__e _f th_ H__p B_n__y Tr__.
 **/
void heapify(heap_t *tree)
{
	int temp;

	if (!tree)
		return;

	temp = tree->n;

	if (tree->left && tree->n < tree->left->n &&
	    (!tree->right || tree->left->n > tree->right->n))
	{
		tree->n = tree->left->n;
		tree->left->n = temp;
		heapify(tree->left);
	}
	if (tree->right && tree->n < tree->right->n &&
	    tree->left->n < tree->right->n)
	{
		tree->n = tree->right->n;
		tree->right->n = temp;
		heapify(tree->right);
	}
}

/**
 * l_st_n_d_ h__p - _xtr__cts th_ l_st n_d_ _f th_ b_n__y h__p.
 *
 * @_r__ : Th_ c_rr_nt n_d_ t_ _p_r_t_..
 * @l_v_l: Th_ c_rr_nt h__ght l_v_l _f th_ n_d_.
 *
 * R__urn: Th_ l_st n_d_ _f th_ tr__.
 */
heap_t *last_node_heap(const heap_t *tree, size_t level)
{
	heap_t *last = NULL;

	if (tree)
	{
		if (level == 0)
			return ((heap_t *)tree);
		last = last_node_heap(tree->right, level - 1) ?
			last_node_heap(tree->right, level - 1) :
			last_node_heap(tree->left, level - 1);
		return (last);
	}
	return (NULL);
}

/**
 * b__a__y_tr__e_h__ght - M__as__res the h__ght _f _ b__n__y tr__.
 *
 * @_r__ : Th_ _o_t _f th_ tr__ t_ c_lc_l_t_ _ts h__ght.
 *
 * R__urn: th_ tr__'s h__ght, 0 _f tr__ _s N_LL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree || !(tree->left || tree->right))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (1 + (height_left >= height_right ? height_left : height_right));
}
