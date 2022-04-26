#include "doublylist.h"

int removeDLElement(DoublyList* pList, int position)
{
    DoublyListNode  *preNode;
    DoublyListNode  *delNode;
    int         ret;
    int         idx;

    if (pList == NULL)
        return (FALSE);
    if (position < 0 || pList->currentElementCount - 1 < position)
        return (FALSE);
    ret = 0;
    idx = 0;
    preNode = &(pList->headerNode);
    while (idx < position)
    {
        preNode = preNode->pRLink;
        idx++;
    }
    delNode = preNode->pRLink;
    preNode->pRLink = delNode->pRLink;
    delNode->pRLink->pLLink = preNode;
    free(delNode);
    pList->currentElementCount -= 1;
    return (TRUE);
}