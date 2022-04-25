#include "doublylist.h"

int main()
{
    int            i;
    int            tmp;
    DoublyList     *pList;
    DoublyListNode newNode;
    
    pList = createDoublyList();
    if(pList != NULL)
    {
        printf("add Element!!!!!!!!!!!!");
        i = -1;
        tmp = 10;
        while (++i < 4)
        {
            newNode.data = tmp;
            addDLElement(pList, i, newNode);
            tmp += 10;
        }
        printf("after 10, 20, 30, 40 add\n");
        displayDoublyList(pList);
        printf("position zero remove\n");
        removeDLElement(pList, 0);
        printf("after remove\n");

        printf("get [1]: %d\n", getDLElement(pList, 1)->data);
        displayDoublyList(pList);
        deleteDoublyList(&pList);
    }
    return (0);
}