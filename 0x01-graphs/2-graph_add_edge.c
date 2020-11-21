#include "graphs.h"

/**
 * insertEdge - insert a new edge to the edges list of the src vertix
 * @src: is the vertex that has the edge
 * @newEdge: is the new edge to be added
 * Return: 1 in success, 0 on failure
 */
int insertEdge(vertex_t *src, edge_t *newEdge)
{
	edge_t *index = NULL;

	if (!src || !newEdge)
		return (0);

	index = src->edges;

	if (!index)
	{
		src->edges = newEdge;
		return (1);
	}

	while (index->next)
	{
		index = index->next;
	}

	index->next = newEdge;
	return (1);
}

/**
 * createEdge - creates a new edge from the given src to dest vertex
 * @src: is the origin vertex
 * @dest: is the destination vertex
 * Return: a pointer to the new edge, or NULL on failure
 */
edge_t *createEdge(vertex_t *src, vertex_t *dest)
{
	edge_t *newEdge = NULL;

	if (!src || !dest)
		return (NULL);

	newEdge = malloc(sizeof(*newEdge));
	if (!newEdge)
		return (NULL);
	newEdge->dest = dest;
	newEdge->next = NULL;
	if (!insertEdge(src, newEdge))
	{
		free(newEdge);
		return (NULL);
	}

	return (newEdge);
}

/**
 * graph_add_edge - add an edge to the graph
 * @graph: is the given graph structure
 * @src: is the content of te new vertex
 * @dest: is the destination of the edge
 * @type: is the type of direction
 * Return: 1 in success 0 otherwise
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
				   edge_type_t type)
{
	vertex_t *source = NULL, *destination = NULL, *index = NULL;
	edge_t *sourceDirection = NULL, *destinationDirection = NULL;

	if (EARLY_RETURN(graph, src, dest, type))
		return (0);

	index = graph->vertices;

	while (index)
	{
		if (!strcmp(src, index->content))
			source = index;
		if (!strcmp(dest, index->content))
			destination = index;
		index = index->next;
	}
	if (!source || !destination)
		return (0);

	sourceDirection = createEdge(source, destination);
	if (!sourceDirection)
		return (0);

	if (type == BIDIRECTIONAL)
	{
		destinationDirection = createEdge(destination, source);
		if (!destinationDirection)
		{
			free(sourceDirection);
			sourceDirection = NULL;
			return (0);
		}
	}

	return (1);
}
