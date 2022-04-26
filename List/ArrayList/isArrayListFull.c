#include "arraylist.h"

int isArrayListFull(ArrayList* pList)
{
    if (!pList)
    {
        printf("Error in isArrayListFull: pList is null\n");
        return (FALSE);
    }
    return (pList->currentElementCount == pList->maxElementCount);
}
