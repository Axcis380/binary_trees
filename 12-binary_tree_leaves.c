#include "binary_trees.h"

/**
 * binr_tre_is_lf - chs f a nd is a lf
 * @nd: pinter to the nd to chck
 *
 * Rtrn: 1 f nd is a lf, nd 0 othwse. If nd s NL, rtrn 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binr_tre_lv - cunts the lvs in a binr tre
 * @tre: pinter to the rot nd of the tre to cunt the lvs in
 *
 * Descrpton: A NUL pinter is not a lv
 *
 * Rtrn: nmbr of lvs in a binr tre
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return (left + right);
}
