#include "heap.h"

/**
 * binary_tree_node - creates a new node
 * @parent: is the parent of the new node,
 * @data: is the given data
 * Return: a new Node or NULL on fail
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent,
									 void *data)
{
	binary_tree_node_t *node = NULL;

	node = calloc(1, sizeof(*node));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->data = data;

	return (node);
}
