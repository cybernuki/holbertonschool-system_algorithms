#ifndef PATH_FINDING_H
#define PATH_FINDING_H

#include "graphs.h"
#include "queues.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define NUM_DIRECTIONS 4
#define euclidean_dist(x1, y1, x2, y2) sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
#define h(x1, y1, x2, y2) (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))

/**
 * struct vertex_queue_s - queue used for Dijkstra's algorithm
 * @vq_src: pointer to source vertex queue node
 * @dest: pointer to destination vertex node
 * @weight: weight of going from src to dest
 * @dist: euclidean distance from dest to target vertex
 * @next: pointer to next queue node
 */
typedef struct vertex_queue_s
{
	struct vertex_queue_s *vq_src;
	vertex_t *dest;
	int weight;
	double dist;
	struct vertex_queue_s *next;
} vertex_queue_t;

/**
 * enum direction_s - which way to go
 * @RIGHT: go east
 * @BOTTOM: go down
 * @LEFT: go west
 * @TOP: go up
 */
enum direction_s
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
};

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
					  vertex_t const *target);

#endif
