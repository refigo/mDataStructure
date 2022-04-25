#include "circularlist.h"

void displayCircularList(CircularList* pList)
{
    int                 idx;
    CircularListNode    *tmp;

    idx = -1;
    tmp = pList->headerNode.pLink;
    while (++idx < pList->currentElementCount)
    {
        printf("order [%d] : %d\n", idx, tmp->data);
        tmp = tmp->pLink;
    }
}