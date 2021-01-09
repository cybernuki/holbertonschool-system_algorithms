#include "pathfinding.h"

/**
 * backtracker - find the path to the target
 * @graph: is the given graph
 * @start: is the given start vertex
 * @target: is the given target vertex
 * @queue: is the solution path
 * @track: is the visited vertices
 * Return: 1 on success, 0 on failure
 */
int backtracker(graph_t *graph, vertex_t const *start,
				vertex_t const *target, queue_t *queue, char *track)
{
	edge_t *edge = NULL;
	char *city = NULL;

	if (track[start->index])
		return (0);
	printf("Checking %s\n", start->content);

	track[start->index] = 1, city = strdup(start->content);

	if (!city)
		exit(1);

	queue_push_front(queue, city);

	if (start == target)
		return (1);

	edge = start->edges;
	while (edge)
	{
		if (backtracker(graph, edge->dest, target, queue, track))
			return (1);
		edge = edge->next;
	}

	free(dequeue(queue));
	return (0);
}

/**
 * backtracking_graph - searches for the first path from a starting point to
 * a target point in a graph.
 * @graph: is the graph
 * @start: is the start vertex
 * @target: is the target vertex
 * Return: a queue with the shortest path
 */
queue_t *
backtracking_graph(graph_t *graph, vertex_t const *start,
				   vertex_t const *target)
{
	queue_t *queue = queue_create(), *path = queue_create();
	char *track = NULL, *city = NULL;

	if (!graph || !start || !target ||
		!queue || !path)
		return (NULL);

	track = calloc(graph->nb_vertices, sizeof(*track));
	if (!track)
		exit(1);
	if (backtracker(graph, start, target, queue, track))
	{
		city = dequeue(queue);
		while (city)
		{
			if (!queue_push_front(path, city))
				exit(1);
			city = dequeue(queue);
		}
	}

	queue_delete(queue);
	free(track);
	return (path);
}
