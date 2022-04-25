#include "linkedlist.h"
#include <stdio.h>

void    displayLinkedList(LinkedList *pList)
{
    ListNode    *curr;
    int         i;

    if (!pList)
        return ;
    curr = &(pList->headerNode);
    i = 0;
    while (curr->pLink)
    {
        curr = curr->pLink;
        printf("[%d]: %d\n", i, curr->data);
        i++;
    }
}