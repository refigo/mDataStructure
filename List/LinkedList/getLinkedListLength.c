#include "linkedlist.h"

int getLinkedListLength(LinkedList* pList)
{
    if (!pList)
    {
        printf("Error: pList is null in getLinkedListLength\n");
        return (-1);
    }
    return (pList->currentElementCount);
}