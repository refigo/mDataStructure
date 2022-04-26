#include "linkedlist.h"

void    displayLinkedList(LinkedList *pList)
{
    ListNode    *curr;
    int         i;

    if (!pList)
    {
        printf("Error: pList is null in displayLinkedList\n");
        return ;
    }
    curr = pList->headerNode.pLink;
    i = 0;
    while (curr)
    {
        printf("LinkedListNode[%d]: %d\n", i, curr->data);
        curr = curr->pLink;
        i++;
    }
}