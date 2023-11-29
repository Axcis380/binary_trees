#include "binary_trees.h"
#include <stdio.h>

/**
 * reater_than - chck f all values in the tre are reater than a valu
 * @tre: pointer tothe ree to chck
 * @va: value to chc against
 *
 * Retrn:1 if tru, 0 if flse
 */
int greater_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		l = greater_than(tree->left, val);
		r = greater_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * ss_than - ck if all values in the tree are less than a specific value
 * @tre: pointer to the tree to check
 * @al: value to check against
 *
 * eturn: 1 if rue, 0 if alse
 */
int less_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		l = less_than(tree->left, val);
		r = less_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * bi_tree_s_bst - chks if a bi tr is a vl bi srch tr
 * @tre: pointer to the root node of the tr to chck
 *
 * Rtrn: 1 if tr is a vl BST, and 0 otherwise. If tr is NULL, rtrn 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (less_than(tree->left, tree->n) && greater_than(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}

	}
	return (0);
}
