#include "circularlist.h"

void clearCircularList(CircularList* pList)
{
    if (pList == NULL)
        return ;
    while (pList->currentElementCount > 0)
        removeDLElement(pList, 0);
}