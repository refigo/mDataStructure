#include "arraylist.h"
#include <stdio.h>

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    ArrayListNode   *ret;

    if (!pList)
    {
        printf("Error in getALElement: pList is null\n");
        return (NULL);
    }
    if (position > (pList->currentElementCount - 1))
    {
        printf("index out of range\n");
        return (NULL);
    }
    ret = &(pList->pElement[position]);
    return (ret);
}