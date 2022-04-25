#include "circularlist.h"

void clearCircularList(CircularList* pList)
{
    while (pList->currentElementCount > 0)
        removeDLElement(pList, 0);
}