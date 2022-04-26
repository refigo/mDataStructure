#include "arraylist.h"

void clearArrayList(ArrayList* pList)
{
    int idx;

    if (!pList)
    {
        printf("Error: pList is null in clearArrayList\n");
        return ;
    }
    idx = -1;
    while (++idx < pList->currentElementCount)
        pList->pElement[idx].data = 0;
    pList->currentElementCount = 0;
}