#include "doublylist.h"

void displayDoublyList(DoublyList* pList)
{
    int             idx;
    DoublyListNode  *tmpNode;

    if (pList == NULL)
        return ;
    tmpNode = pList->headerNode.pRLink;
    idx = 0;
    while (idx < pList->currentElementCount)
    {
        printf("dbly list [%d]: %d\n", idx, tmpNode->data);
        idx++;
        tmpNode = tmpNode->pRLink;
    }
}