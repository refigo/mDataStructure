#include "circularlist.h"

void deleteCircularList(CircularList* pList)
{
    if (pList == NULL)
        return ;
    clearCircularList(pList);
    free(pList);
}