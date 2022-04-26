#include "arraylist.h"

void displayArrayList(ArrayList* pList)
{
    int idx;

    if (!pList)
    {
        printf("Error: pList is null in displayArrayList\n");
        return ;
    }
    idx = -1;
    while (++idx < pList->currentElementCount)
        printf("pElement[%d]: %d\n", idx, pList->pElement[idx].data);
}