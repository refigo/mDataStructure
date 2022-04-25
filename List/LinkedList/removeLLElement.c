#include "linkedlist.h"

int removeLLElement(LinkedList* pList, int position)
{
    ListNode    *preNode;
    ListNode    *toRemove;
    int          i;

    if (!pList)
    {
        printf("Error in removeLLElement: pList is null\n");
        return (FALSE);
    }
    if (position < 0 || position >= (pList->currentElementCount))
    {
        printf("Error in removeLLElement: position out of range\n");
        return (FALSE);
    }
    preNode = &(pList->headerNode);
    i = -1;
    while (++i < position)
        preNode = preNode->pLink;
    toRemove = preNode->pLink;
    preNode->pLink = toRemove->pLink;
    free(toRemove);
    pList->currentElementCount -= 1;
    return (TRUE);
}