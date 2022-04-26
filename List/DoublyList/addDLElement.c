#include "doublylist.h"

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    DoublyListNode  *preNode;
    DoublyListNode  *postNode;
    DoublyListNode  *newNode;
    int             ret;
    int             idx;

    if (pList == NULL)
        return (FALSE);
    if (position < 0 || pList->currentElementCount < position)
        return (FALSE);
    newNode = malloc(sizeof(DoublyListNode));
    if (newNode == NULL)
        return (FALSE);
    *newNode = element;
    ret = 0;
    idx = 0;
    preNode = &(pList->headerNode);
    while (idx < position)
    {
        preNode = preNode->pRLink;
        idx++;
    }
    postNode = preNode->pRLink;
    newNode->pRLink = postNode;
    postNode->pLLink = newNode;
    newNode->pLLink = preNode;
    preNode->pRLink = newNode;
    pList->currentElementCount += 1;
    return (TRUE);
}