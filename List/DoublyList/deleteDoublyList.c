#include "doublylist.h"

void deleteDoublyList(DoublyList* pList)
{
    if (pList == NULL)
        return ;
    clearDoublyList(pList);
    free(pList);
}