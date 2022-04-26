#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *pStack;

	pStack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (pStack == NULL)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	pStack->currentElementCount = 0;
	pStack->pTopElement = NULL;
	return (pStack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;

	if (pStack == NULL)
		return (ERROR);
	new = malloc(sizeof(StackNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	(pStack->currentElementCount)++;
	return (TRUE);
}

// 사용자가 ret에 대한 메모리 관리를 알아서 잘해야 함
StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*ret;

	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	ret = pStack->pTopElement;
	pStack->pTopElement = ret->pLink;
	ret->pLink = 0;
	(pStack->currentElementCount)--;
	return (ret);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (pStack == NULL)
		return ;
	while (pStack->currentElementCount)
		free(popLS(pStack));
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (ERROR);
	return (pStack->currentElementCount == 0);
}

/*
int main(void)
{
	LinkedStack *pStack;
	StackNode element;

	element.data = 42;

	pStack = createLinkedStack();
	
	for (int i = 0; i < 5; i++)
	{
		pushLS(pStack, element);
		element.data++;
	}
	for (int i = 0; i < 6; i++)
	{
		if (isLinkedStackEmpty(pStack) == FALSE)
			printf("%d ", popLS(pStack)->data);
	}
	if (isLinkedStackEmpty(pStack))
		printf("all pops done. empty!\n");
	printf("\n");
	pushLS(pStack, element);
	deleteLinkedStack(pStack);
	pStack = 0;
	pushLS(pStack, element);
	return (0);
}
*/