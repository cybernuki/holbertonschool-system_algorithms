#include "heap.h"

/**
 * heapify_down - restores the min heap property from root down
 * @heap: pointer to heap struct
 */
void heapify_down(heap_t *heap)
{
	binary_tree_node_t *node = heap->root, *child;
	void *tmp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = heap->data_cmp(node->left->data, node->right->data) <= 0 ? node->left : node->right;
		if (heap->data_cmp(node->data, child->data) < 0)
			break;
		tmp = node->data;
		node->data = child->data;
		child->data = tmp;
		node = child;
	}
}

/**
 * heap_extract -extract a node from the heap
 *
 * @heap: is the root of the heap
 * Return: value extracted null on error
 */
void *heap_extract(heap_t *heap)
{
	void *data = NULL;
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

	heapify_down(heap);
	return (data);
}