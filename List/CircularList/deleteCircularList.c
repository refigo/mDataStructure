#include "circularlist.h"

void deleteCircularList(CircularList** pList)
{
    clearCircularList(*pList);
    free(*pList);
    *pList = NULL;
}