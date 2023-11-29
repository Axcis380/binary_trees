#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * This function finds the lowest common ancestor node of two given nodes
 * in a binary tree. It takes pointers to the first and second nodes and
 * returns a pointer to their lowest common ancestor.
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    binary_tree_t *tmp;

    if (first == NULL || second == NULL)
        return (NULL);

    tmp = (binary_tree_t *)second;
    while (first)
    {
        while (second)
        {
            if (first == second)
                return ((binary_tree_t *)first);
            second = second->parent;
        }
        second = tmp;
        first = first->parent;
    }
    return (NULL);
}
