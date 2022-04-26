#include "arraylist.h"

/*
    Not handle dangling pointer beacause this function doesn't mention it.
*/

void deleteArrayList(ArrayList* pList)
{
    if (!pList)
    {
        printf("Error: pList is null in deleteArrayList\n");
        return ;
    }
    free(pList->pElement);
    free(pList);
}
