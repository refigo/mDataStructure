#include "circularlist.h"

void displayCircularList(CircularList* pList)
{
    int                 idx;
    CircularListNode    *tmp;

    if (pList == NULL)
        return ;
    idx = -1;
    tmp = pList->headerNode.pLink;
    while (++idx < pList->currentElementCount)
    {
        printf("CircularListNode[%d] : %d\n", idx, tmp->data);
        tmp = tmp->pLink;
    }
}