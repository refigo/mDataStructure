#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode    *preNode;
    ListNode    *added;
    int         i;

    if (!pList)
    {
        printf("Error in addLLElement: pList is null\n");
        return (FALSE);
    }
    if (position < 0 || position > (pList->currentElementCount))
    {
        printf("Error in addLLElement: position out of range\n");
        return (FALSE);
    }
    added = malloc(sizeof(ListNode));
    if (!added)
    {
        printf("Error in addLLElement: malloc failed\n");
        return (FALSE);
    }
    (*added) = element;
    preNode = &(pList->headerNode);
    i = -1;
    while (++i < position)
        preNode = preNode->pLink;
    added->pLink = preNode->pLink;
    preNode->pLink = added;
    pList->currentElementCount += 1;
    return (TRUE);
}