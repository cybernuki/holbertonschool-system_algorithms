#include "graphs.h"

/**
 * graph_add_edge - add an edge to the graph
 * @graph: is the given graph structure
 * @src: is the content of te new vertex
 * @dest: is the destination of the edge
 * @type: is the type of direction
 * Return: 1 in success 0 otherwise
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{

    if (EARLY_RETURN(graph, src, dest, type))
        return (0);

    return (1);
}
