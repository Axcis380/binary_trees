#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_1 - Creates a binary tree node with a specified parent and value.
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 *
 * Returns: Pointer to the new node.
 */
binary_tree_t *binary_tree_node_1(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->parent = parent;
    new_node->n = value;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

/**
 * binary_tree_insert_left - Inserts a new node as the left-child of a specified node.
 * @parent: Pointer to the node where the left-child will be inserted.
 * @value: Value to be stored in the new node.
 *
 * This function inserts a new node containing the given value as the left-child of
 * the specified parent node. If the parent already has a left-child, the new node
 * replaces it, and the existing left-child becomes the left-child of the new node.
 *
 * Returns: Pointer to the newly created node, or NULL if allocation fails.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return (NULL);

    binary_tree_t *left_child = binary_tree_node_1(parent, value);
    if (left_child == NULL)
        return (NULL);

    left_child->left = parent->left;
    if (left_child->left != NULL)
        left_child->left->parent = left_child;

    parent->left = left_child;
    return (left_child);
}

/**
 * binary_tree_search - Searches for a value in a binary tree.
 * @tree: Pointer to the root node of the tree to search.
 * @value: Value to search for in the tree.
 *
 * Returns: Pointer to the node containing the found value, otherwise NULL.
 */
binary_tree_t *binary_tree_search(const binary_tree_t *tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (tree->n == value)
        return ((binary_tree_t *)tree);

    binary_tree_t *left_result = binary_tree_search(tree->left, value);
    if (left_result != NULL)
        return (left_result);

    return binary_tree_search(tree->right, value);
}
