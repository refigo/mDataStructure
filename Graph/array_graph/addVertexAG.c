#include "arraygraph.h"

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (vertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if ((pGraph->pVertex)[vertexID] == USED)
        return (FALSE);
    (pGraph->pVertex)[vertexID] = USED;
    (pGraph->currentVertexCount) += 1;
    return (SUCCESS);
}