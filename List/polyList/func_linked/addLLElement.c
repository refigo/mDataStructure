#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode    *preNode;
    ListNode    *added;
    int         i;

    if (pList->currentElementCount < position)
    {
        printf("position out of range\n");
        return (FALSE);
    }
    added = malloc(sizeof(ListNode));
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