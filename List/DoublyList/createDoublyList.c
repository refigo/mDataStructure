#include "doublylist.h"

DoublyList* createDoublyList()
{
    DoublyList  *new;
    new = malloc(sizeof(DoublyList));
    if (new == NULL)
    {
        printf("malloc failed\n");
        return (NULL);
    }
    memset((void *)new, 0, sizeof(DoublyList));
    //처음에 자기자신을 바라봐야함
    new->headerNode.pLLink = &(new->headerNode);
    new->headerNode.pRLink = &(new->headerNode);
    return (new);
}