#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode    *preNode;
    ListNode    *added;
    int         i;

    if (!pList)
    {
        printf("Error: pList is null in addLLElement\n");
        return (FALSE);
    }
    if (position < 0 || position > (pList->currentElementCount))
    {
        printf("Error: position out of range in addLLElement\n");
        return (FALSE);
    }
    added = malloc(sizeof(ListNode));
    if (!added)
    {
        printf("Error: malloc failed in addLLElement\n");
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