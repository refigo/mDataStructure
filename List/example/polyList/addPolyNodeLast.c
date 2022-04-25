#include "linkedlist.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
    ListNode    *new;
    ListNode    *tmp;
    int         i;

    tmp = &(pList->headerNode);
    i = -1;
    while (++i < pList->currentElementCount)
        tmp = tmp->pLink;
    new = malloc(sizeof(ListNode));
    if (new == NULL)
        return (FALSE);
    new->coef = coef;
    new->degree = degree;
    new->pLink = NULL;
    tmp->pLink = new;
    pList->currentElementCount += 1;
    return (TRUE);
}