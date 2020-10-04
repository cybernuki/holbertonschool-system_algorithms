#include "rb_trees.h"

/**
 * rb_tree_node - add a new node
 * @parent: is the parent of the new node
 * @value: is the value assigned
 * @color: is the assigned color
 * Return: the new node or null in failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *newNode = malloc(sizeof(*newNode));

	if (!newNode)
		return (NULL);

	memset(newNode, 0, sizeof(*newNode));
	newNode->parent = parent;
	newNode->n = value;
	newNode->color = color;
	return (newNode);
}