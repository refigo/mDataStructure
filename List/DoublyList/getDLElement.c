#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
    DoublyListNode  *getNode;
    int             idx;

    if (pList == NULL)
        return (NULL);
    getNode = &(pList->headerNode);
    idx = -1;
    while (idx < position)
    {
        getNode = getNode->pRLink;
        idx++;
    }
    return (getNode);
}