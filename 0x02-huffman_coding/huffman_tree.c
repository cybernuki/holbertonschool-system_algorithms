#include "huffman.h"

/**
 * huffman_tree - build a huffman tree
 * @data: is an array with the data
 * @freq: is an array with the frequencies
 * @size: is the size of both arrays
 * Return: A huffman tree or Null on failure;
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *queue = NULL;
	binary_tree_node_t *root = NULL;

	queue = huffman_priority_queue(data, freq, size);

	if (!queue)
		return (NULL);

	while (1)
		if (!huffman_extract_and_insert(queue))
			break;

	root = queue->root->data, free(queue->root), free(queue);
	return (root);
}
