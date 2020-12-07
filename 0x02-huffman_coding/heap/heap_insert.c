#include "heap.h"

/**
 * setBitNumber - set the most significant bite
 * for the given number
 * @n: is the given number
 * Return: the most significant bit of the given number
 */
size_t setBitNumber(size_t n)
{
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n = n + 1;
	return (n >> 1);
}

/**
 * heap_insert - inserts new node into heap
 * @heap: pointer to heap structure
 * @data: pointer to data
 * Return: pointer to new node or NULL
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node = NULL, *parent = NULL, *index = NULL;
	size_t parentPath = 0, parentIndex = 0;
	void *tmp;

	if (!heap)
		return (NULL);
	node = binary_tree_node(NULL, data);
	if (!node)
		return (NULL);

	parentIndex = ++heap->size / 2;
	parentPath = setBitNumber(parentIndex) >> 1;
	if (!heap->root)
		return (heap->root = node);
	for (parent = heap->root; parentPath; parentPath >>= 1)
		parent = (parentPath & parentIndex) ? parent->right : parent->left;

	node->parent = parent;
	if (heap->size & 1)
		parent->right = node;
	else
		parent->left = node;

	index = node;
	while (index->parent && heap->data_cmp(index->parent->data, index->data) > 0)
	{
		tmp = index->data;
		index->data = index->parent->data;
		index->parent->data = tmp;
		index = index->parent;
	}
	return (node);
}
