#include "graphs.h"

/**
 * recur_traverse - depth first traverse with recursion
 * @index: vertix index
 * @vistedPath: visited vertices
 * @depth: detph of the first traverse
 * @max_depth: is the current max_depth
 * @action: function pointer which print an the current value node
 * Return: the deepest depth on success or 0 otherwise
 */
size_t traverse(vertex_t *index, char *vistedPath, size_t depth,
				size_t max_depth, void (*action)(const vertex_t *v, size_t depth))
{
	edge_t *edge_index = NULL;
	size_t sub_max = 0;

	if (!index)
	{
		return (depth);
	}
	action(index, depth);
	vistedPath[index->index] = 'v';
	edge_index = index->edges;
	while (edge_index)
	{
		if (vistedPath[edge_index->dest->index] == 'v')
		{
			edge_index = edge_index->next;
			continue;
		}
		sub_max = traverse(edge_index->dest, vistedPath,
						   depth + 1, max_depth, action);
		max_depth = sub_max > max_depth ? sub_max : max_depth;
		edge_index = edge_index->next;
	}

	max_depth = depth > max_depth ? depth : max_depth;
	return (max_depth);
}

/**
 * depth_first_traverse - run through a graph using depth first traverse
 * @graph: the graph struct
 * @action: function pointer which print an the current value node
 * Return: the deepest depth on success or 0 otherwise
 */
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth))
{
	char vistedPath[2048] = {0};

	if (!graph || !action)
		return (0);

	return (traverse(graph->vertices, vistedPath, 0, 0, action));
}
