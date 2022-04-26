#include "arraylist.h"

ArrayList   *createArrayList(int maxElementCount)
{
	ArrayList       *ret;
	ArrayListNode   *node;

	if (maxElementCount <= 0)
	{
		printf("Error: maxElementCount should positive in createArrayList\n");
		return (NULL);
	}
	ret = malloc(sizeof(ArrayList));
	if (!ret)
	{
		printf("Error: malloc failed in createArrayList\n");
		return (NULL);
	}
	ret->maxElementCount = maxElementCount;
	ret->currentElementCount = 0;
	node = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!node)
	{
		printf("Error: malloc failed in createArrayList\n");
		return (NULL);
	}
	ret->pElement = node;
	return (ret);
}