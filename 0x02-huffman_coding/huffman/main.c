#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: is the argc
 * @argv: is the argv
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Usage: huffman <mode> <filename> <out_filename>\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
