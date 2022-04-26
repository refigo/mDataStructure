#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
    int last_idx;
    int cnt;

    if (!pList)
    {
        printf("Error: pList is null in removeALElement\n");
        return (FALSE);
    }
    if (pList->currentElementCount - 1 < position)
    {
        printf("Error: position is out of range in removeALElement\n");
        return (FALSE);
    }
    last_idx = pList->currentElementCount - 1;
    cnt = last_idx - position;
    while (cnt--)
    {
        pList->pElement[position] = pList->pElement[position + 1];
        position++;
    }
    pList->currentElementCount -= 1;
    return (TRUE);
}