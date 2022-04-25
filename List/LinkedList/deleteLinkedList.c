#include "linkedlist.h"
#include <stdlib.h>

void deleteLinkedList(LinkedList** pList)
{
    ListNode    *curr;
    ListNode    *tmp;

    if (!pList)
    {
        printf("Error in deleteLinkedList: pList is null\n");
        return ;
    }
    curr = (*pList)->headerNode.pLink;
    while (curr)
    {
        tmp = curr;
        curr = curr->pLink;
        free(tmp);
    }
    free(*pList);
    *pList = NULL;
}
