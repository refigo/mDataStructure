#include "circularlist.h"

int addDLElement(CircularList* pList, int position, CircularListNode element)
{
    CircularListNode    *preNode;
    CircularListNode    *newNode;
    int                 idx;
    
    if (pList == NULL || pList->currentElementCount < position || position < 0)
        return (FALSE);
    newNode = malloc(sizeof(CircularList));
    *newNode = element;
    preNode = &(pList->headerNode);
    idx = -1;
    while (++idx < position)
        preNode = preNode->pLink;
    newNode->pLink = preNode->pLink;
    preNode->pLink = newNode;
    pList->currentElementCount += 1;
    if (newNode->pLink == NULL)
        newNode->pLink = newNode;
    return (TRUE);
}