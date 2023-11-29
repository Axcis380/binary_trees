#include "binary_trees.h"
#include <stdlib.h>
#include <stdbool.h> // Include this header for using boolean values

/**
 * binary_tree_node - Creates a new binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Returns: Pointer to the newly created node, or NULL if memory allocation fails.
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

/**
 * binary_tree_search - Searches for a value in a binary tree.
 * @tree: Pointer to the root node of the tree to search.
 * @value: Value to search for in the tree.
 *
 * Returns: true if the value is found, false otherwise.
 */
bool binary_tree_search(const binary_tree_t *tree, int value)
{
    if (tree == NULL)
        return false;

    if (tree->n == value)
        return true;

    bool left_result = binary_tree_search(tree->left, value);
    if (left_result)
        return true;

    return binary_tree_search(tree->right, value);
}

int main(void)
{
    // Creating a sample binary tree
    binary_tree_t *root = binary_tree_node(NULL, 10);
    root->left = binary_tree_node(root, 5);
    root->right = binary_tree_node(root, 15);
    root->left->left = binary_tree_node(root->left, 3);
    root->left->right = binary_tree_node(root->left, 8);
    root->right->left = binary_tree_node(root->right, 12);
    root->right->right = binary_tree_node(root->right, 18);

    // Check if the value 80 exists in the tree
    bool value_80_exists = binary_tree_search(root, 80);

    if (value_80_exists) {
        printf("Value 80 exists in the tree.\n");
    } else {
        printf("Value 80 doesn't exist in the tree.\n");
    }

    // Remember to free memory allocated for the tree nodes if no longer needed

    return 0;
}
