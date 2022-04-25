#include "doublylist.h"

int getDoublyListLength(DoublyList* pList)
{
    if (pList == NULL)
    {
        //길이가 0이면 0을 리턴하니까 -1로 헷갈리지 않게
        return (-1);
    }        
    return (pList->currentElementCount);
}