#include "heap.h"

/**
 * heap_extract -extract a node from the heap
 *
 * @heap: is the root of the heap
 * Return: value extracted null on error
 */
void *heap_extract(heap_t *heap)
{
	void *data = NULL, *tmp = NULL;
	binary_tree_node_t *lastNode = NULL, *parent = NULL;
	size_t path = 0;

	if (!heap || !heap->size)
		return (NULL);

	if (heap->size == 1)
	{
		data = heap->root->data;
		free(heap->root), heap->root = NULL, heap->size--;
		return (data);
	}

	path = setBitNumber(heap->size) >> 1;
	for (lastNode = heap->root; path; path >>= 1)
		lastNode = (path & heap->size) ? lastNode->right : lastNode->left;

	data = heap->root->data;
	heap->root->data = lastNode->data;
	parent = lastNode->parent, free(lastNode);
	if (heap->size-- & 1)
		parent->right = NULL;
	else
		parent->left = NULL;

	path = setBitNumber(heap->size) >> 1;
	for (lastNode = heap->root; path; path >>= 1)
		lastNode = (path & heap->size) ? lastNode->right : lastNode->left;

	while (lastNode->parent)
	{
		if (heap->data_cmp(lastNode->parent->data, lastNode->data) > 0)
		{
			tmp = lastNode->data;
			lastNode->data = lastNode->parent->data;
			lastNode->parent->data = tmp;
		}
		lastNode = lastNode->parent;
	}
	return (data);
}