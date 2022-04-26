#include "doublylist.h"

DoublyList* createDoublyList()
{
    DoublyList  *new;

    new = malloc(sizeof(DoublyList));
    if (new == NULL)
        return (NULL);
    memset((void *)new, 0, sizeof(DoublyList));
    new->headerNode.pLLink = &(new->headerNode);
    new->headerNode.pRLink = &(new->headerNode);
    return (new);
}