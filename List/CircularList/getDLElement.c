#include "circularlist.h"

CircularListNode* getDLElement(CircularList* pList, int position)
{
    int                 idx;
    CircularListNode    *tmpNode;
    if (pList == NULL || position < 0 || pList->currentElementCount - 1 < position)
        return (NULL);
    idx = -1;
    tmpNode = pList->headerNode.pLink;
    while(++idx < position)
        tmpNode = tmpNode->pLink;
    return (tmpNode);
}