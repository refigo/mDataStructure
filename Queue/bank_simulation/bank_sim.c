#include	"simdef.h"


void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pDeque)
{
	DequeNode	newNode;

	if (pDeque == NULL)
		return ;
	newNode.data.status = arrival;
	newNode.data.arrivalTime = arrivalTime;
	newNode.data.serviceTime = processTime;
	newNode.data.startTime = -1;
	newNode.data.endTime = -1;
	newNode.pRLink = NULL;
	newNode.pLLink = NULL;
	insertRearLD(pDeque, newNode);
}

void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque)
{
	DequeNode	*moving;

	if (pArrivalDeque == NULL || pWaitDeque == NULL \
		|| pArrivalDeque->currentElementCount == 0)
		return ;
	moving = peekFrontLD(pArrivalDeque);
	if (moving->data.arrivalTime != currentTime)
	{
		free(moving);
		return ;
	}
	free(moving);
	moving = deleteFrontLD(pArrivalDeque);
	if (moving == NULL)
		return ;
	insertRearLD(pWaitDeque, *moving);
	free(moving);
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque)
{
	DequeNode	*starting;

	if (pWaitDeque == NULL || pWaitDeque->currentElementCount == 0)
		return (NULL);
	starting = deleteFrontLD(pWaitDeque);
	if (starting == NULL)
		return (NULL);
	starting->data.status = start;
	starting->data.startTime = currentTime;
	starting->data.endTime = starting->data.startTime + starting->data.serviceTime;
	return (starting);
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, \
	int *pServiceUserCount, int *pTotalWaitTime)
{
	pServiceNode->data.endTime = currentTime;
	pServiceNode->data.status = end;
	(*pServiceUserCount)++;
	(*pTotalWaitTime) += currentTime - pServiceNode->data.arrivalTime - pServiceNode->data.serviceTime;
	return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	if (customer.status == arrival)
		printf("status : arrival, ");
	else if (customer.status == start)
		printf("status : start, ");
	else if (customer.status == end)
		printf("status : end, ");
	printf("arrivalTime %d, serviceTime %d, startTime %d, endTime %d\n", \
		 customer.arrivalTime, customer.serviceTime, customer.startTime, customer.endTime);
}

void printWaitDequeStatus(int currentTime, LinkedDeque *pWaitDeque)
{
	DequeNode	*printNode;

	if (pWaitDeque == NULL)
		return ;
	printf("\n----------------\nWaitDeque(currentTime %d)\n", currentTime);
	printNode = pWaitDeque->pFrontNode;
	for (int i = 1; printNode; i++)
	{
		printf("waiting customer %d : \n", i);
		printSimCustomer(currentTime, printNode->data);
		printNode = printNode->pRLink;
	}
}

void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime, int currentTime)
{
	if (pWaitDeque == NULL)
		return ;
	printWaitDequeStatus(currentTime, pWaitDeque);
	if (serviceUserCount == 0)
		return ;
	printf(" finished service count : %d \n", serviceUserCount);
	printf(" average waiting time : %.3f\n", (float)totalWaitTime / (float)serviceUserCount);
}


int	simulationFCFS(LinkedDeque *pArrivalDeque)
{
	LinkedDeque	*pWaitDeque;
	DequeNode *pServiceNode;
	int	currentTime = 0;
	int serviceUserCount = 0;
	int totalWaitTime = 0;

	pServiceNode = NULL;
	pWaitDeque = createLinkedDeque();
	while (1) // currentTime <= 10
	{
		processArrival(currentTime, pArrivalDeque, pWaitDeque);
		if (pServiceNode && pServiceNode->data.endTime == currentTime)
		{
			pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
			free(pServiceNode);
			pServiceNode = NULL;
		}
		if (pServiceNode == NULL)
			pServiceNode = processServiceNodeStart(currentTime, pWaitDeque);
		printReport(pWaitDeque, serviceUserCount, totalWaitTime, currentTime);
		if (pServiceNode == NULL && pWaitDeque->currentElementCount == 0 \
			&& pArrivalDeque->currentElementCount == 0)
			break;
		currentTime++;
	}
	deleteLinkedDeque(pWaitDeque);
	return (1);
}

int	main(void)
{
	LinkedDeque	*pArrivalDeque;

	pArrivalDeque = createLinkedDeque();
	insertCustomer(0, 3, pArrivalDeque);
	insertCustomer(2, 2, pArrivalDeque);
	insertCustomer(4, 1, pArrivalDeque);
	insertCustomer(6, 1, pArrivalDeque);
	insertCustomer(8, 3, pArrivalDeque);

	simulationFCFS(pArrivalDeque);
	
	deleteLinkedDeque(pArrivalDeque);
	system("leaks a.out");
	return (0);
}
