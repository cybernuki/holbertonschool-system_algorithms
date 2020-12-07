#include "heap.h"

/**
 * heap_create - creates a new heap with
 * the given comparision function
 * @data_cmp: is the function to compare the nodes
 * Return: a new allocated heap or NULL on error
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = NULL;

	heap = calloc(1, sizeof(*heap));
	if (!heap)
		return (NULL);

	heap->data_cmp = data_cmp;
	return (heap);
}
