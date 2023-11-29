#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotaion on a binay tree
 * @tree: pointer to the root nde o the tree to roae
 *
 * Return: a poier o the ne root node of the treeonce rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->right;
	if (tree->right)
	{
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;
		if (tree->right)
			tree->right->parent = tree;
		return (tree->parent);
	}
	return (tree);
}
