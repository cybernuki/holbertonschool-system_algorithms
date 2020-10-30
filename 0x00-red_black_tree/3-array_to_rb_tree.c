#include "rb_trees.h"

/**
 * array_to_rb_tree - converts an array to an instance of a
 * red-black tree
 * @array: is the given array
 * @size: is the size of the array
 * Return: the root of the tree
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *root = NULL;
	size_t i = 0;

	for (; i < size; i++)
		rb_tree_insert(&root, array[i]);

	return (root);
}
