#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
    int idx = pList->currentElementCount - 1;
    int cnt = idx - position;

    if (!pList)
    {
        printf("Error in removeALElement: pList is null\n");
        return (FALSE);
    }
    if (pList->currentElementCount - 1 < position)
    {
        printf("Error in removeALElement: position is out of range\n");
        return (FALSE);
    }
    while (cnt--)
    {
        pList->pElement[position] = pList->pElement[position + 1];
        position++;
    }
    pList->currentElementCount -= 1;
    return (TRUE);
}