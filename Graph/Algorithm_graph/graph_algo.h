#ifndef GRAPH_ALGO_H
# define GRAPH_ALGO_H

#include "heap.h"
#include "arraygraph.h"

#include "dijkstra.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define SKYBLUE "\033[1;36m"
#define WHITE "\033[1;37m"
#define EOC "\033[0;0m"


void    kruskal(ArrayGraph *graph, ArrayGraph *MST);
void	prim(ArrayGraph *graph, ArrayGraph *PrimMST, int rootVertexID);

void	floyd(ArrayGraph *graph, ArrayGraph *FloydPath);

#endif