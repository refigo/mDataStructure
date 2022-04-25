#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode    *node;
    int         i;
    
    if (pList->currentElementCount < position)
    {
        printf("position out of range\n");
        return (FALSE);
    }
    node = pList->headerNode.pLink;
    i = -1;
    while (++i < position)
        node = node->pLink;
    return (node);
}
