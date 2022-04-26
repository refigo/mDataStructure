#include "arraylist.h"

int getArrayListLength(ArrayList* pList)
{
    if (!pList)
    {
        printf("Error: pList is null in getArrayListLength\n");
        return (-1);
    }
    return (pList->currentElementCount);
}