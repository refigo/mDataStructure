#include "linkedlist.h"

/*
    Not handle dangling pointer beacause this function doesn't mention it.
*/

void deleteLinkedList(LinkedList* pList)
{
    ListNode    *curr;
    ListNode    *tmp;

    if (!pList)
    {
        printf("Error: pList is null in deleteLinkedList\n");
        return ;
    }
    curr = pList->headerNode.pLink;
    while (curr)
    {
        tmp = curr;
        curr = curr->pLink;
        free(tmp);
    }
    free(pList);
}
