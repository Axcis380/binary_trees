#include "binary_trees.h"

/**
 * bst_srch - srchs for a value in a binry srch tre
 * @tre: pointer to the rot node of the BS to srch
 * @vale: vale to srch in the tre
 *
 * Rtrn: pointer to the node contaning a vale eql to vale, or NUL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	tmp = (bst_t *)tree;
	while (tmp)
	{
		if (tmp->n == value)
			return (tmp);
		if (tmp->n < value)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (NULL);
}
