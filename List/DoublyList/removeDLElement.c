#include "doublylist.h"

int removeDLElement(DoublyList* pList, int position)
{
    int         ret;
    int         idx;
    DoublyListNode  *preNode;
    DoublyListNode  *delNode;

    //position에 음수가 들어왔거나, current가 더 적으면
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