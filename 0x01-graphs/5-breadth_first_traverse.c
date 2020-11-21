#include "graphs.h"

/**
 * recur_traverse - breadth first traverse with recursive, look for all nodes
 * @cp_ve_header: vertix header
 * @len_gra: lenght of the graph
 * @depth: current detph
 * @m_depth: max detph of traverse
 * @action: function pointer which print an the current value node
 * Return: the deepest depth on success or 0 otherwise
 */
size_t recur_traverse(vertex_t *cp_ve_header, char *len_gra, size_t depth,
					  size_t m_depth, void (*action)(const vertex_t *v, size_t depth))
{
	size_t flag = 0;
	edge_t *cp_ed_header = NULL;

	if (!cp_ve_header)
		return (0);
	cp_ed_header = cp_ve_header->edges;
	if (depth != m_depth)
	{
		if (!cp_ed_header)
			return (0);
		return (recur_traverse(cp_ed_header->dest,
							   len_gra, depth + 1, m_depth, action));
	}

	while (cp_ed_header)
	{
		if (len_gra[cp_ed_header->dest->index] == 0)
		{
			action(cp_ed_header->dest, depth);
			len_gra[cp_ed_header->dest->index] = 1;
			flag = 1;
		}
		cp_ed_header = cp_ed_header->next;
	}
	if (!flag)
		return (0);
	return (depth);
}

/**
 * traverse - breadth first traverse with iteration, iterate each edge
 * @index: vertix header
 * @visitedPath: lenght of the graph
 * @action: function pointer which print an the current value node
 * Return: the deepest depth on success or 0 otherwise
 */
size_t traverse(vertex_t *index, char *visitedPath,
				void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth_n = 0, max_depth = 0, flag = 0, flag_e = 1, i = 2;
	edge_t *copy_index = NULL;

	copy_index = index->edges;
	while (copy_index)
	{
		if (visitedPath[copy_index->dest->index] == 0)
		{
			action(copy_index->dest, 1);
			visitedPath[copy_index->dest->index] = 1;
			flag = 1;
		}
		copy_index = copy_index->next;
	}
	if (flag)
		max_depth = 1;
	while (flag_e != 0)
	{
		flag_e = 0;
		copy_index = index->edges;
		while (copy_index)
		{
			depth_n = recur_traverse(copy_index->dest, visitedPath, 2, i, action);
			if (depth_n > max_depth)
				max_depth = depth_n;
			if (depth_n > 0)
				flag_e = 1;
			copy_index = copy_index->next;
		}
		i++;
	}
	return (max_depth);
}

/**
 * breadth_first_traverse - run through a graph using breadth first traverse
 * @graph: the graph struct
 * @action: function pointer which print an the current value node
 * Return: the deepest depth on success or 0 otherwise
 */
size_t breadth_first_traverse(const graph_t *graph,
							  void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *index = NULL;
	char visitedPath[2048] = {0};
	size_t depth_n = 0, max_depth = 0;

	if (!graph || !action)
		return (0);

	index = graph->vertices;

	while (index)
	{
		if (visitedPath[index->index] == 0)
		{
			action(index, 0);
			visitedPath[index->index] = 1;
			depth_n = traverse(index, visitedPath, action);
			if (depth_n > max_depth)
				max_depth = depth_n;
		}
		index = index->next;
		break;
	}
	return (max_depth);
}
