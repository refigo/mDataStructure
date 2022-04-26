#include "circularlist.h"

int getCircularListLength(CircularList* pList)
{
    if (pList == NULL)
        return (-1);
    return (pList->currentElementCount);
}