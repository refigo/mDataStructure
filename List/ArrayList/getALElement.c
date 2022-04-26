#include "arraylist.h"

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    ArrayListNode   *ret;

    if (!pList)
    {
        printf("Error: pList is null in getALElement\n");
        return (NULL);
    }
    if (position > (pList->currentElementCount - 1))
    {
        printf("Error: index out of range in getALElement\n");
        return (NULL);
    }
    ret = &(pList->pElement[position]);
    return (ret);
}