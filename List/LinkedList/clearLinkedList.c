#include "linkedlist.h"

void clearLinkedList(LinkedList* pList)
{
    ListNode    *curr;
    ListNode    *tmp;

    if (!pList)
    {
        printf("Error: pList is null in clearLinkedList\n");
        return ;
    }
    curr = pList->headerNode.pLink;
    while (curr)
    {
        tmp = curr;
        curr = curr->pLink;
        free(tmp);
    }
    pList->headerNode.pLink = 0;
    pList->currentElementCount = 0;
}
