#include "graph_algo.h"

#define F_INFINITY -1

void	floyd(ArrayGraph *graph, ArrayGraph *FloydPath)
{
	for (int i = 0; i < graph->maxVertexCount; i++)
		addVertexAG(FloydPath, i);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		for (int j = 0; j < graph->maxVertexCount; j++)
		{
			if (i == j)
				FloydPath->ppAdjEdge[i][j] = 0;
			else if (graph->ppAdjEdge[i][j] <= 0)
				FloydPath->ppAdjEdge[i][j] = F_INFINITY;
			else
				FloydPath->ppAdjEdge[i][j] = graph->ppAdjEdge[i][j];
		}
	}

	for (int k = 0; k < graph->maxVertexCount; k++)
		for (int i = 0; i < graph->maxVertexCount; i++)
			for (int j = 0; j < graph->maxVertexCount; j++)
			{
				if (FloydPath->ppAdjEdge[i][k] != F_INFINITY \
				&& FloydPath->ppAdjEdge[k][j] != F_INFINITY \
				&& (FloydPath->ppAdjEdge[i][j] == F_INFINITY \
					|| FloydPath->ppAdjEdge[i][j] > FloydPath->ppAdjEdge[i][k] + FloydPath->ppAdjEdge[k][j]))
				{
					FloydPath->ppAdjEdge[i][j] = FloydPath->ppAdjEdge[i][k] + FloydPath->ppAdjEdge[k][j];
				}
			}

	printf("\n%s-----Floyd algorithm-----%s\n", PURPLE, EOC);
	displayArrayGraph(FloydPath);
	printf("%s-----done Floyd-----%s\n", PURPLE, EOC);
}
