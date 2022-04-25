#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    LinkedList  *ret;

    ret = malloc(sizeof(LinkedList));
    if (!ret)
    {
        printf("Error in createLinkedList: malloc failed\n");
        return (NULL);
    }
    ret->currentElementCount = 0;
    ret->headerNode.data = 0;
    ret->headerNode.pLink = 0;
    return (ret);
}