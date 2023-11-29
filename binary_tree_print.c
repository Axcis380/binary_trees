#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * pr_nt_t - St_r_s r_c_rs_v_ly __ch l_v_l _n _n _rr_y _f str_ngs
 *
 * @tr__: P__nt__r t_ th_ n_d_ t_ pr_nt
 * @_ffs_t: _ffs_t t_ pr_nt
 * @d_pth: D_pth _f th_ n_d_
 * @s: B_ff_r
 *
 * R__urn: l_ng_h _f pr_nt_d tr__ _ft_r pr_c_ss
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _h__ght - M__asur_s th_ h__ght _f _ b__n__y tr__
 *
 * @tr__: P__nt__r t_ th_ n_d_ t_ m__asur_ th_ h__ght
 *
 * R__urn: Th_ h__ght _f th_ tr__ st_rt_ng _t @n_d_
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * b__a__y_tr__e_pr__nt - Pr__nts _ b__n__y tr__
 *
 * @_r__ : P__nt__r t_ th_ r__t n__e _f th_ tr__ t_ pr__nt
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
