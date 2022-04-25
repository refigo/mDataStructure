
#include "arraylist.h"

void clearArrayList(ArrayList* pList)
{
    int idx;

    if (!pList)
    {
        printf("Error in clearArrayList: pList is null\n");
        return ;
    }
    idx = -1;
    while (++idx < pList->currentElementCount)
        pList->pElement[idx].data = 0;
}