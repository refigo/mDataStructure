#include "circularlist.h"

CircularList* createCircularList()
{
    CircularList    *new;

    new = malloc(sizeof(CircularList));
    if (new == NULL)
        return (FALSE);
    memset(new, 0, sizeof(CircularList));
    return (new);
}