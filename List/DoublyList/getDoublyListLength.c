#include "doublylist.h"

int getDoublyListLength(DoublyList* pList)
{
    if (pList == NULL)
        return (-1);
    return (pList->currentElementCount);
}