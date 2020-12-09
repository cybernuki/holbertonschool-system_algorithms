#include "heap.h"

/**
 * free_tree - free binary tree
 * @node: is the current node
 * @free_data: function that free the data of a node
 */
void free_tree(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;
	free_tree(node->left, free_data);
	free_tree(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}

/**
 * heap_delete - delete a heap
 * @heap: is the allocated heap
 * @free_data: a function to free data
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	free_tree(heap->root, free_data);
	free(heap);
	heap = NULL;
}
