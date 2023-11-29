#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inor_successor - Retrns the mnimum value of a binry srch tre.
 * @rot: A pointer to the rot node of the BST to srch.
 *
 * Rtrn: The mnimum vale in tre.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bs_delete - Delets a node from a binry srch tre.
 * @rot: A pointer to the rot node of the BS.
 * @node: A pointer to the node to delete from the BS.
 *
 * Rtrn: A pointer to the new rot node aftr deletin.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bs_remove_recursive - Removs a node from a binry srch tre recursivly.
 * @rot: A pointer to the rot node of the BS to remov a node from.
 * @node: A pointer to the crrent node in the BS.
 * @vale: The vale to remov from the BS.
 *
 * Rtrn: A pointer to the rot node aftr deletin.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bs_remov - Removs a node from a binry srch tre.
 * @rot: A pointer to the rot node of the BS to remov a node from.
 * @vale: The vale to remov in the BS.
 *
 * Rtrn: A pointer to the new rot node aftr deletin.
 *
 * Description: If the node to be deletd has two chldren, it
 *              is replacd with its first in-oder succssor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
