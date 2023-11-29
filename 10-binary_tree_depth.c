#include "binary_trees.h"
#include <stdio.h> // Include this header for printf

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @node: Pointer to the node to measure the depth of.
 *
 * This function calculates the depth of a specified node within a binary tree.
 * If the node is NULL, the function returns 0 representing the depth.
 *
 * Return: Depth of a node in a binary tree. If the node is NULL, return 0.
 */

size_t binary_tree_depth(const binary_tree_t *node)
{
    size_t count = 0;

    if (node == NULL)
        return (count);

    while (node->parent != NULL)
    {
        count++;
        node = node->parent;
    }
    return (count);
}

/**
 * binary_tree_search_value - Searches for a value in a binary tree.
 * @tree: Pointer to the root node of the tree to search.
 * @value: Value to search for in the tree.
 *
 * Returns: 1 if the value is found, 0 otherwise.
 */
int binary_tree_search_value(const binary_tree_t *tree, int value)
{
    if (tree == NULL)
        return 0;

    if (tree->n == value)
        return 1;

    int left_result = binary_tree_search_value(tree->left, value);
    if (left_result)
        return 1;

    return binary_tree_search_value(tree->right, value);
}

int main(void)
{
    // Create a sample binary tree (you can modify this based on your tree)
    binary_tree_t *root = /* Create your binary tree here */;

    // Check if the value 80 exists in the tree
    int value_80_exists = binary_tree_search_value(root, 80);

    if (value_80_exists) {
        printf("Value 80 exists in the tree.\n");
    } else {
        printf("Value 80 doesn't exist in the tree.\n");
    }

    // Remember to free memory allocated for the tree nodes if no longer needed

    return 0;
}
