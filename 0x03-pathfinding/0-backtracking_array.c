#include "pathfinding.h"

/**
 * backtracker - executes a backtracking for find one path to target
 * @track: is the visited nodes in the matrix
 * @rows: numer of rows of the matrix
 * @cols: numer of cols of the matrix
 * @target: is the target point
 * @x: is the current x position
 * @y: is the current y position
 * @queue: is the current queue
 * Return: 1 on success, 0 on failure
 */
int backtracker(char **track, int rows, int cols, point_t const *target,
				int x, int y, queue_t *queue)
{
	point_t *point = calloc(1, sizeof(*point));

	if (!point)
		exit(1);

	if (track[y][x] != '0' || x < 0 || x >= cols || y < 0 || y >= rows)
		return (0);
	point->x = x, point->y = y, track[y][x] = '1';

	queue_push_front(queue, point);
	printf("Checking coordinates [%d, %d]\n", x, y);

	if ((x == target->x && y == target->y) ||
		(backtracker(track, rows, cols, target, x + 1, y, queue) ||
		 backtracker(track, rows, cols, target, x, y + 1, queue) ||
		 backtracker(track, rows, cols, target, x - 1, y, queue) ||
		 backtracker(track, rows, cols, target, x, y - 1, queue)))
		return (1);

	free(dequeue(queue));
	return (0);
}

/**
 * backtracking_array - searches for the first path from a starting
 * point to a target point within a two-dimensional array.
 * @map: is the grid map
 * @rows: are the number of rows
 * @cols: are the number of cols
 * @start: is the start point
 * @target: is the target point
 * Return: a queue with the shortest path
 */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target)
{
	queue_t *queue = queue_create(), *path = queue_create();
	point_t *point = NULL;
	char **track = malloc(rows * sizeof(char *));
	int i = 0;

	if (!map || !queue || !path || !track ||
		rows < 0 || cols < 0 ||
		!start || !target)
		return (NULL);

	for (i = 0; i < rows; i++)
	{
		track[i] = malloc(cols + 1);
		if (!track[i])
			exit(1);
		strcpy(track[i], map[i]);
	}

	if (!backtracker(track, rows, cols, target, start->x, start->y, queue))
		free(queue), queue = NULL, free(queue);
	else
	{
		while ((point = dequeue(queue)))
			queue_push_front(path, point);
		free(queue);
	}

	for (i = 0; i < rows; i++)
		free(track[i]);
	free(track);

	return (path);
}
