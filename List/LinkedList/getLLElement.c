#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode    *node;
    int         i;
    
    if (!pList)
    {
        printf("Error in getLLElement: pList is null\n");
        return (NULL);
    }
    if (position < 0 || position >= (pList->currentElementCount))
    {
        printf("Error in getLLElement: position out of range\n");
        return (FALSE);
    }
    node = &(pList->headerNode);
    i = -1;
    while (++i <= position)
        node = node->pLink;
    return (node);
}
