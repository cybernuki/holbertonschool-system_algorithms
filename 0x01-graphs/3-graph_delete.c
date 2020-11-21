#include "graphs.h"

/**
 * graph_delete - delete a graph structure
 * @graph: the graph struct
 */
void graph_delete(graph_t *graph)
{
	vertex_t *index = NULL, *next = NULL;
	edge_t *edge_index = NULL, *edge_next = NULL;

	if (!graph)
		return;
	index = graph->vertices;
	while (index)
	{
		next = index->next;
		if (index->content)
			free(index->content);

		edge_index = index->edges;
		while (edge_index)
		{
			edge_next = edge_index->next;
			free(edge_index);
			edge_index = edge_next;
		}
		free(index);
		index = next;
	}
	free(graph);
}
