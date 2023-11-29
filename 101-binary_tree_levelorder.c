#include "binary_trees.h"

/**
 * binary_tree_height - meaures the height of a bin tre
 * @tree: pointr to the rot node of the tre to mease the heght of
 *
 * Return: the hight of the tre. If tre is NUL, return 0
 */
size_t binary_tre_height(const binary_tree_t *tree)
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
 * binary_tree_level - perform a fnctin on a specfic level of a bin tre
 * @tree: pointero the roo of the tre
 * @l: level of th tree to performa functin on
 * @func: fuction to perfor
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		binary_tree_level(tree->left, l - 1, func);
		binary_tree_level(tree->right, l - 1, func);
	}
}

/**
 * binary_tree_levelorder - trarses a binry treusng level-order travesal
 * @tree: pointer tothe root nde of the tee to traverse
 * @func: pointer to a function t cal for eah node.
 * The value in the noe must bepased as a parameter to this function
 *
 * Return: voi
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}
