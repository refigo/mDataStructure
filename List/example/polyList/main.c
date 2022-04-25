#include "polylist.h"

LinkedList* createLinkedList()
{
    LinkedList  *ret;

    ret = malloc(sizeof(LinkedList));
    memset(ret, 0, sizeof(LinkedList));
    return (ret);
}

void deleteLinkedList(LinkedList** pList)
{
    ListNode    *curr;
    ListNode    *tmp;

    curr = (*pList)->headerNode.pLink;
    while (curr && curr->pLink)
    {
        tmp = curr;
        curr = curr->pLink;
        free(tmp);
    }
    free(*pList);
    *pList = 0;
}

int	putRemains(LinkedList *result, ListNode **curr)
{
	while (*curr)
	{
		addPolyNodeLast(result, (*curr)->coef ,(*curr)->degree);
		*curr = (*curr)->pLink;
	}
	return (TRUE);
}

LinkedList	*integralPolyList(LinkedList *poly_a, LinkedList *poly_b)
{
	LinkedList	*ret;
	ListNode	*node_a;
	ListNode	*node_b;

	ret = createLinkedList();
	if (ret == NULL)
		return (NULL);
	node_a = poly_a->headerNode.pLink;
	node_b = poly_b->headerNode.pLink;
	while (node_a != NULL || node_b != NULL)
	{
		if (node_a == NULL)
			putRemains(ret, &node_b);
		else if (node_b == NULL)
			putRemains(ret, &node_a);
		else if (node_a->degree > node_b->degree)
		{
			addPolyNodeLast(ret, node_a->coef, node_a->degree);
			node_a = node_a->pLink;
		}
		else if (node_a->degree < node_b->degree)
		{
			addPolyNodeLast(ret, node_b->coef, node_b->degree);
			node_b = node_b->pLink;
		}
		else if (node_a->degree == node_b->degree)
		{
			addPolyNodeLast(ret, node_a->coef + node_b->coef, node_a->degree + node_b->degree);
			node_a = node_a->pLink;
			node_b = node_b->pLink;
		}
	}
	return (ret);
}

void	displayPoly(LinkedList *poly)
{
	ListNode	*tmp;
	int			i;

	i = 0;
	tmp = poly->headerNode.pLink;
	while (tmp)
	{
		if (i > 0)
			printf(" + ");
		printf("%.fx^%d", tmp->coef, tmp->degree);
		tmp = tmp->pLink;
		i++;
	}
	printf("\n");
}

int main(void) {
	LinkedList	*poly_a;
	LinkedList	*poly_b;
	LinkedList	*result;

	poly_a = createLinkedList();
	poly_b = createLinkedList();

	// a: 5x^3 ....
	addPolyNodeLast(poly_a, 5, 5);
	addPolyNodeLast(poly_a, 1, 3);
	addPolyNodeLast(poly_a, 5, 1);
	displayPoly(poly_a);

	// b: ...
	addPolyNodeLast(poly_b, 4, 4);
	addPolyNodeLast(poly_b, 4, 3);
	addPolyNodeLast(poly_b, 4, 2);
	displayPoly(poly_b);

	result = integralPolyList(poly_a, poly_b);
	displayPoly(result);

	deleteLinkedList(&poly_a);
	deleteLinkedList(&poly_b);
	deleteLinkedList(&result);
	return (0);
}