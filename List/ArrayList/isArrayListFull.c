#include "arraylist.h"

int isArrayListFull(ArrayList* pList)
{
    if (!pList)
    {
        printf("Error: pList is null in isArrayListFull\n");
        return (FALSE);
    }
    return (pList->currentElementCount == pList->maxElementCount);
}
