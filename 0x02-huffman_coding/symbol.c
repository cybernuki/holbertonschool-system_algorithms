#include "huffman.h"

/**
 * symbol_create - creates a new symbol
 * @data: is the data
 * @freq: is the frequency of the data appearance
 * Return: a pointer to the new symbol, NULL on fail
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol = malloc(sizoeof(*symbol));

	if (!symbol)
		return (NULL);

	symbol->data = data, symbol->freq = freq;
	return (symbol);
}
