#include "linkedlist.h"
#include <stdlib.h>

void deleteLinkedList(LinkedList** pList)
{
    ListNode    *curr;
    ListNode    *tmp;

    curr = (*pList)->headerNode.pLink;
    while (curr && curr->pLink)
    {
        tmp = curr;
        curr = curr->pLink;
        free(tmp);
    }
    free(*pList);
    *pList = 0;
}
