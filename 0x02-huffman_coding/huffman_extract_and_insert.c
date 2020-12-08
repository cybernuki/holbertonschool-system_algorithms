#include "huffman.h"

/**
 * huffman_extract_and_insert - extracts the two least frequent symbols from
 * our priority queue, add their frequencies, and store this new frequency
 * back in our priority queue.
 * @priority_queue: is the priority_queue
 * Return: 1 in success, 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	symbol_t *symbol = NULL, *symbol1 = NULL, *symbol2 = NULL;
	binary_tree_node_t *child1 = NULL, *child2 = NULL, *nested = NULL;

	if (!priority_queue || priority_queue->size < 2)
		return (0);

	child1 = heap_extract(priority_queue);
	child2 = heap_extract(priority_queue);
	if (!child1 || !child2)
		return (0);

	symbol1 = (symbol_t *)child1->data;
	symbol2 = (symbol_t *)child2->data;
	symbol = symbol_create(-1, symbol1->freq + symbol2->freq);
	if (!symbol)
		return (0);
	nested = binary_tree_node(NULL, symbol);
	if (!nested)
		return (free(symbol), 0);

	nested->left = child1;
	nested->right = child2;
	child1->parent = nested;
	child2->parent = nested;

	if (heap_insert(priority_queue, nested))
		return (1);
	return (0);
}
