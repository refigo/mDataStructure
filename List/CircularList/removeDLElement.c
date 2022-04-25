#include "circularlist.h"

int removeDLElement(CircularList* pList, int position)
{
    int                 idx;
    CircularListNode    *delNode;
    CircularListNode    *preNode;

    if (pList == NULL || position < 0 || position > pList->currentElementCount - 1)
        return (FALSE);
    
    idx = -1;
    preNode = &(pList->headerNode);
    while (++idx < position)
        preNode = preNode->pLink;
    delNode = preNode->pLink;
    preNode->pLink = delNode->pLink;
    if (preNode->pLink == delNode)
        preNode->pLink = NULL;
    free(delNode);
    pList->currentElementCount -= 1;
    return (TRUE);
}