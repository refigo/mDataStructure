#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode    *node;
    int         i;
    
    if (!pList)
    {
        printf("Error: pList is null in getLLElement\n");
        return (NULL);
    }
    if (position < 0 || position >= (pList->currentElementCount))
    {
        printf("Error: position out of range in getLLElement\n");
        return (NULL);
    }
    node = &(pList->headerNode);
    i = -1;
    while (++i <= position)
        node = node->pLink;
    return (node);
}
