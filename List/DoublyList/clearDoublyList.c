#include "doublylist.h"

void clearDoublyList(DoublyList* pList)
{
    if (pList == NULL)
        return ;
    while(pList->currentElementCount > 0)
        removeDLElement(pList, 0);
}