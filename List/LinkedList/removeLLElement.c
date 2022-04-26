#include "linkedlist.h"

int removeLLElement(LinkedList* pList, int position)
{
    ListNode    *preNode;
    ListNode    *toRemove;
    int          i;

    if (!pList)
    {
        printf("Error: pList is null in removeLLElement\n");
        return (FALSE);
    }
    if (position < 0 || position >= (pList->currentElementCount))
    {
        printf("Error: position out of range in removeLLElement\n");
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