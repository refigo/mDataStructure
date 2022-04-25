#include "linkedlist.h"
#include <stdlib.h>

void clearLinkedList(LinkedList* pList)
{
    ListNode    *curr;
    ListNode    *tmp;

    if (!pList)
    {
        printf("Error in clearLinkedList: pList is null\n");
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
