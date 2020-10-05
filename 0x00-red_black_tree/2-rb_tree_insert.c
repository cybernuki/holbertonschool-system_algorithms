#include "rb_trees.h"

/**
 * insert_fixup - fix the tree
 * @tree: is the tree
 * @node: is a node
 */
void insert_fixup(rb_tree_t **tree, rb_tree_t *node)
{
    rb_tree_t *parent = NULL, *uncle = NULL;

    while (parent = GETPARENT(node) && parent->color == RED)
    {
        if (parent == GETANCESTOR(node)->left)
        {
            uncle = GETANCESTOR(node)->right;
            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                node = GETANCESTOR(node);
            }
            else if (node == parent->right)
        }
        else
    }
}

/**
 * rb_tree_insert - insert a new node in the red black tree
 * @tree: is the tree
 * @value: is the value to be insert
 * Return: a pointer to the new node, NULL in failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
    rb_tree_t *newNode = malloc(sizeof(*newNode));
    rb_tree_t *current = NULL, *previous = NULL;

    if (!tree || !newNode)
        return (NULL);

    memset(newNode, 0, sizeof(*newNode));
    newNode->n = value;
    newNode->color = RED;

    current = *tree;
    while (current)
    {
        previous = current;
        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }
    newNode->parent = previous;
    if (!previous)
        *tree = newNode;
    else if (value < previous->n)
        previous->left = newNode;
    else
        previous->right = newNode;

    insert_fixup(tree, newNode);
    return (newNode);
}