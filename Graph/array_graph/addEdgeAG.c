#include "arraygraph.h"

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (((pGraph->pVertex)[fromVertexID] == NOT_USED) \
        || ((pGraph->pVertex)[toVertexID] == NOT_USED))
        return (FALSE);
    if ((pGraph->ppAdjEdge)[fromVertexID][toVertexID] > 0)
        return (FALSE);
    (pGraph->ppAdjEdge)[fromVertexID][toVertexID] = 1;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        addEdgeAG(pGraph, toVertexID, fromVertexID);
    return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (pGraph == NULL)
        return (ERROR);
    if (((pGraph->pVertex)[fromVertexID] == NOT_USED) \
        || ((pGraph->pVertex)[toVertexID] == NOT_USED))
        return (FALSE);
    if ((pGraph->ppAdjEdge)[fromVertexID][toVertexID] > 0)
        return (FALSE);
    (pGraph->ppAdjEdge)[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        addEdgewithWeightAG(pGraph, toVertexID, fromVertexID, weight);
    return (SUCCESS);
}
