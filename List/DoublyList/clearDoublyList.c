#include "doublylist.h"

void clearDoublyList(DoublyList* pList)
{
    int         cnt;

    cnt = 0;
    if(pList != NULL)
    {
        while(pList->currentElementCount > 0)
        {
            //tmp position에다가 무줙건 0 싹다 삭제 시키고
            removeDLElement(pList, 0);
            // current를 1씩 줄여주면
            pList->currentElementCount -= 1;
        }
    }
    printf("wrong structer!!!!");
}