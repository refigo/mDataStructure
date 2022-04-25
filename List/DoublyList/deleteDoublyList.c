#include "doublylist.h"

void deleteDoublyList(DoublyList** pList)
{
    int         cnt;

    //댕글링 포인터의 존재를 어떻게 처리해야 하는지? 사용자에게 맡길 것이냐, 아님 자체적으로 NULL로 줄 것이냐
    cnt = 0;
    if(pList != NULL)
    {
        while((*pList)->currentElementCount > 0)
        {
            //tmp position에다가 무줙건 0 싹다 삭제 시키고
            removeDLElement(*pList, 0);
            // current를 1씩 줄여주면
            (*pList)->currentElementCount -= 1;
        }
        free(*pList);
        *pList = NULL;
    }
    printf("wrong structer!!!!");
}