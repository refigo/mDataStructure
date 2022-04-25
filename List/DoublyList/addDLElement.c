#include "doublylist.h"

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    int         ret;
    int         idx;
    DoublyListNode  *preNode;
    DoublyListNode  *postNode;
    DoublyListNode  *newNode;

    //position에 음수가 들어왔거나 current보다 큰 인덱스를 줬거나
    if (position < 0 || pList->currentElementCount < position)
        return (FALSE);
    newNode = malloc(sizeof(DoublyListNode));
    if (newNode == NULL)
        return (FALSE);
    *newNode = element;
    ret = 0;
    idx = 0;
    preNode = &(pList->headerNode);
    while (idx < position)
    {
        preNode = preNode->pRLink;
        idx++;
    }
    postNode = preNode->pRLink;
    //1. 추가할 노드가 그 다음 노드를 바라보게 하기
    newNode->pRLink = postNode;
    //2. 그 다음 노드가 새 노드를 바라보기
    postNode->pLLink = newNode;
    //3. 새 노드 이전노드를 보게 하기
    newNode->pLLink = preNode;
    //4. 이전 노드가 새 노드 바라보게 하기
    preNode->pRLink = newNode;
    pList->currentElementCount += 1;
    return (TRUE);
}