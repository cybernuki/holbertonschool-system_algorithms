#include "huffman.h"

/**
 * tree_decode - go throug the tree and find the codes
 * @node: is the current node,
 * @path: is a bit mask that represent the path
 * Return: 1 in success, 0 on failure
 */
int tree_decode(binary_tree_node_t *node, size_t path)
{
	int result = 0;
	size_t index = 0;

	if (!node)
		return (0);
	if (!node->left || !node->right)
	{
		printf("%c: ", ((symbol_t *)node->data)->data);
		index = setBitNumber(path) >> 1;
		while (index)
		{
			printf("%c", (path & index) ? '1' : '0');
			index >>= 1;
		}
		printf("\n");
		free(node->data);
		free(node);
		return (1);
	}

	result = tree_decode(node->left, path << 1);
	result = result && tree_decode(node->right, (path << 1) + 1);
	free(node->data);
	free(node);
	return (result);
}

/**
 * huffman_codes - get the huffman code for each character
 * in a given data array
 * @data: is the data array
 * @freq: is the frequency array
 * @size: is the size of both arrays
 * Return: 1 in success, 0 on failure
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *tree = huffman_tree(data, freq, size);

	if (!tree)
		return (0);

	return (tree_decode(tree, 1));
}
