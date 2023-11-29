#include "binary_trees.h"

/**
 * rray_to_bst - builds a Binar Srch Tr from an arry
 * @arry: pointer to the frst element of the arry to be conerted
 * @sze: numbr of elmnt in the arry
 *
 * Descripton: If a value of the arry alredy exists, this vale is ignored
 *
 * Rtrn: pointer to the rot node of the creatd BST, or NUL on failre
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
