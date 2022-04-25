#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
    int             idx;
    DoublyListNode  *getNode;

    getNode = &(pList->headerNode);
    if (pList != NULL)
    {
        idx = -1;
        while (idx < position)
        {
            getNode = getNode->pRLink;
            idx++;
        }
    }
    return (getNode);
}