#include "arraylist.h"

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    int cnt;
    int idx;

    if (!pList)
    {
        printf("Error: pList is null in addALElement\n");
        return (FALSE);
    }
    if (pList->currentElementCount == pList->maxElementCount)
    {
        printf("Error: array is full in addALElement\n");
        return (FALSE);
    }
    if (position < 0 || pList->currentElementCount < position)
    {
        printf("Error: index out of range in addALElement\n");
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
        pList->pElement[pList->currentElementCount] = element; // position == current
    pList->currentElementCount += 1;
    return (TRUE);
}
