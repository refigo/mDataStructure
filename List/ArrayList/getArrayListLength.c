#include "arraylist.h"

int getArrayListLength(ArrayList* pList)
{
    if (!pList)
    {
        printf("Error in getArrayListLength: pList is null\n");
        return (-1);
    }
    return (pList->currentElementCount);
}