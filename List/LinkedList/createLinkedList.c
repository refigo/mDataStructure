#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    LinkedList  *ret;

    ret = malloc(sizeof(LinkedList));
    if (!ret)
    {
        printf("Error: malloc failed in createLinkedList\n");
        return (NULL);
    }
    ret->currentElementCount = 0;
    ret->headerNode.data = 0;
    ret->headerNode.pLink = NULL;
    return (ret);
}