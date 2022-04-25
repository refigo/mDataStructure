#include "linkedlist.h"
#include <stdlib.h>

void clearLinkedList(LinkedList* pList)
{
    ListNode    *curr;
    ListNode    *tmp;
    int         i;

    curr = pList->headerNode.pLink;
    i = 0;
    while (curr->pLink)
    {
        tmp = curr;
        curr = curr->pLink;
        free(tmp);
    }
    pList->headerNode.pLink = 0;
    pList->currentElementCount = 0;
}
