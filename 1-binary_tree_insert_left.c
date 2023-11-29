#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_1 - create a biry tre node
 * @parent: parnt of he nde to crat
 * @value: valu t store i new node
 *
 * Return: point to he ew node
 */
binary_tree_t *binary_tree_node_1(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/**
 * binary_tree_insert_left - inserts a node asthe leftchild ofother node
 * @parent: ponter to th node to inset the lefthild in
 * @value: valu to storein thenew nod
 *
 * Description: If parnt already hasa leftild, the newode mus ake its
 * place, and the old leftchild must be setas the leftchild of the new node.
 *
 * Return: poinr to the crated node, or NUL onfaile
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (parent == NULL)
		return (NULL);
	left_child = binary_tree_node_1(parent, value);
	if (left_child == NULL)
		return (NULL);
	left_child->left = parent->left;
	if (left_child->left != NULL)
		left_child->left->parent = left_child;
	parent->left = left_child;
	return (left_child);
}
