#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * hgt - Msrs the hgt of a bnr tr.
 * @tr: A pntr to the rot nd of the tr to msr the hgt.
 *
 * Rtrn: If tr is NL, yr fnctn mst rtrn 0, els rtrn hgt.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * s_avl_helper - Chks if a binry tre is a vl AVL tre.
 * @tre: A pntr to the rot nd of the tre to chck.
 * @lo: The vl of the smlst nd vsitd thus fr.
 * @hi: The vl of the lrgst nd vsitd ths fr.
 *
 * Rtrn: If the tre is a vl AVL tre, 1, othrwse, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binr_tre_is_avl - Chks if a binry tre is a vl AVL tre.
 * @tre: A pntr to the rot nd of the tre to chck.
 *
 * Rtrn: 1 if tre is a vl AVL tre, and 0 othrwse
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
