#include "linkedlist.h"

int getLinkedListLength(LinkedList* pList)
{
    if (!pList)
    {
        printf("Error in getLinkedListLength: pList is null\n");
        return (-1);
    }
    return (pList->currentElementCount);
}