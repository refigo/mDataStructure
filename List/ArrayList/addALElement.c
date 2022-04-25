#include "arraylist.h"

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    int cnt = 0;
    int idx = 0;

    if (!pList)
    {
        printf("Error in addALElement: pList is null\n");
        return (FALSE);
    }
    if (pList->currentElementCount == pList->maxElementCount)
    {
        printf("Error in addALElement: array is full\n");
        return (FALSE);
    }
    if (pList->maxElementCount - 1 < position)
    {
        printf("Error in addALElement: index out of range\n");
        return (FALSE);
    }
    if (pList->currentElementCount > position)
    {
        idx = pList->currentElementCount - 1;
        cnt = idx - position;
        for (int i = 0; i < cnt; i++)
        {
            (pList->pElement)[idx + 1] = (pList->pElement)[idx];
            idx -= 1;
        }
        pList->pElement[position] = element;
    }
    else
    {
        pList->pElement[pList->currentElementCount] = element;
    }
    pList->currentElementCount += 1;
    return (TRUE);
}
