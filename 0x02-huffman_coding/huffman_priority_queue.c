#include "huffman.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
	symbol_t *n1, *n2;

	n1 = ((binary_tree_node_t *)p1)->data;
	n2 = ((binary_tree_node_t *)p2)->data;
	return (n1->freq - n2->freq);
}

/**
 * huffman_priority_queue - build a priority queue
 * @data: is an array of characters
 * @freq: is an array containing the associated frequencies
 * @size: is the size of both arrays
 * Return: a new minumun heap, NULL on failure
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *queue = NULL;
	binary_tree_node_t *nested = NULL;
	symbol_t *symbol = NULL;
	size_t index = 0;

	if (!data || !freq)
		return (NULL);

	queue = heap_create(int_cmp);
	if (!queue)
		return (NULL);

	while (index < size)
	{
		symbol = symbol_create(data[index], freq[index]);
		if (!symbol)
			return (NULL);
		nested = binary_tree_node(NULL, symbol);
		if (!nested)
			return (NULL);
		if (!heap_insert(queue, nested))
			return (NULL);
		index++;
	}
	return (queue);
}
