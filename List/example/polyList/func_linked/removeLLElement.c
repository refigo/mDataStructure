#include "linkedlist.h"

int removeLLElement(LinkedList* pList, int position)
{
    ListNode    *preNode;
    ListNode    *toRemove;
    int          i;

    if (pList->currentElementCount < position)
    {
        printf("position out of range\n");
        return (FALSE);
    }
    preNode = pList->headerNode.pLink;
    i = 0;
    while (++i < position)
        preNode = preNode->pLink;
    toRemove = preNode->pLink;
    preNode->pLink = toRemove->pLink;
    free(toRemove);
    pList->currentElementCount -= 1;
    return (TRUE);
}