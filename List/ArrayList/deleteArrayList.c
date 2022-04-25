
#include "arraylist.h"
#include <stdlib.h>

void deleteArrayList(ArrayList** pList)
{
    if (!pList)
    {
        printf("Error in deleteArrayList: pList is null\n");
        return ;
    }
    free((*pList)->pElement);
    free(*pList);
    *pList = 0;
}