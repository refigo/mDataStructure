#include "linkedlist.h"
#include <stdio.h>

void    displayLinkedList(LinkedList *pList)
{
    ListNode    *curr;
    int         i;

    if (!pList)
    {
        printf("Error in displayLinkedList: pList is null\n");
        return ;
    }
    curr = pList->headerNode.pLink;
    i = 0;
    while (curr)
    {
        printf("[%d]: %d\n", i, curr->data);
        curr = curr->pLink;
        i++;
    }
}