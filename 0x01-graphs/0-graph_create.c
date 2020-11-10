#include "graphs.h"

/**
 * graph_create - allocates memory to initialize a graph structure
 * Return: an initialized graph or null in error
 */
graph_t *graph_create(void)
{
	return (calloc(sizeof(graph_t), 1));
}
