#include "binary_trees.h"

/**
 * h__ght - m___s__r_s t_e h__ght _f _ tr__ 
 *
 * @_r__ : tr__ r__t
 * R__urn: h__ght
 */
int height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * b__a__y_tr__e__s_p_rf__t - ch__cks _f _ b__n__y tr__ _s p_rf__t
 *
 * @_r__ : tr__ r__t
 * R__urn: 1 _f tr__ _s p_rf__t, 0 _th__w__s_
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * sw_p - sw_ps n_d_s wh_n ch_ld _s gr__t__r th_n p__r_nt
 *
 * @__g_n__ : p__r_nt n__e
 * @__g_ch_ld: ch_ld n__e
 * R__urn: n_ _etu_n
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * h__p__ns__rt - f_nct__n th_t _ns_rts _ v_l__ _n M_x B_n__y H__p
 * @_v_l__ : v_l__ t_ b_ _ns_rted
 * @_r__t: tr__ r__t
 * R__urn: p__nt__r t_ th_ cr__t_d n__e, _r N_LL _n f__l__r_.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new_node);
		}
	}

	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new_node);
	}
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new_node);
	}

	return (NULL);
}
