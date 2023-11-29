#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if anode is a leaf
 * @node: pointer to the noe to chck
 *
 * Return: 1 if node is a laf, and 0 otheise. If nde is NUL, retrn 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measus the heght of abinary tre
 * @tree: pointer to the ro nde of the tree to measure the height of
 *
 * Return: the heiht of thtee. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - checs if a biry tre is perfct
 * @tree: pointer to th root nde of the ree to che
 * Return: 1 if prect, 0 othrwise. If tre is NLL, retrn 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (1);
	l = tree->left;
	r = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  check if a bnary tre i complete
 * @tree: point to te rot nod of the tre to heck
 *
 * Return: 1 if complete, 0 otherwse. If ree is NUL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	l_height = binary_tree_height(l);
	r_height = binary_tree_height(r);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
