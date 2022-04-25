#include "linkedlist.h"

LinkedList* createLinkedList()
{
    LinkedList  *ret;

    ret = malloc(sizeof(LinkedList));
    memset(ret, 0, sizeof(LinkedList));
    return (ret);
}