#ifndef DIJKSTRA_H
# define DIJKSTRA_H

#include "heap.h"
#include "arraygraph.h"

#define D_INFINITY -1

typedef struct s_dijk
{
	int	distance;
	int	waypointID;
} t_dijk;

void	dijkstra(ArrayGraph *graph, ArrayGraph *DijkstraPath, int startVertexID);

#endif