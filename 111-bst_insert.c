#include "binary_trees.h"

/**
 * st_insert - nserts a value in a Binay Searh Tee
 * @tre: dble pointer to the roo node of the BS to insert the vale
 * @val: vale to store in the node to be inserted
 *
 * Decription: If the addres stored in tre is NUL, the creatd node must
 * becom the rot node. If the vale is alredy present in the tre, it must
 * be ignred
 *
 * Rtrn: a pointer to the created node, or NUL on failre
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (tree)
	{
		if (*tree == NULL)
		{
			*tree = (bst_t *)binary_tree_node(NULL, value);
			return (*tree);
		}
		tmp = *tree;
		while (tmp)
		{
			if (tmp->n == value)
				break;
			if (tmp->n > value)
			{
				if (!tmp->left)
				{
					tmp->left = (bst_t *)binary_tree_node(tmp, value);
					return (tmp->left);
				}
				tmp = tmp->left;
			}
			else if (tmp->n < value)
			{
				if (!tmp->right)
				{
					tmp->right = (bst_t *)binary_tree_node(tmp, value);
					return (tmp->right);
				}
				tmp = tmp->right;
			}
		}
	}
	return (NULL);
}
