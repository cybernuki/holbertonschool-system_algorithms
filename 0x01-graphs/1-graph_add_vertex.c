#include "graphs.h"

/**
 * graph_add_vertex - add a vertex to the graph
 * @graph: is the given graph structure
 * @str: is the content of te new vertex
 * Return: the position of the new vertex or null on error
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *newVertex = NULL, *index = NULL;

	if (!graph || !str)
		return (NULL);

	newVertex = calloc(sizeof(*newVertex), 1);
	if (!newVertex)
		return (NULL);

	newVertex->content = strdup(str);
	index = graph->vertices;

	if (!index)
	{
		graph->vertices = newVertex;
		graph->nb_vertices++;
		return (newVertex);
	}

	while (index)
	{
		if (!strcmp(index->content, newVertex->content))
		{
			free(newVertex->content);
			return (NULL);
		}
		if (!index->next)
		{
			index->next = newVertex;
			newVertex->index = index->index + 1;
			graph->nb_vertices++;
			return (newVertex);
		}
		index = index->next;
	}

	return (NULL);
}
