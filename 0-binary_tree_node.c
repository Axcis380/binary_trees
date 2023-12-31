#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - cretes a bin tee node
 * @parent: parntof the nodeto crate
 * @value: valueto store n new node
 *
 * Return: poinr to th new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
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
