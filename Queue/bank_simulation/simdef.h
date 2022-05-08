#ifndef	_SIM_DEF_
#define	_SIM_DEF_

#include	<stdlib.h>
#include	<stdio.h>

typedef enum SimStatusType { arrival, start, end } SimStatus;
typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착 시각.
	int serviceTime;	// 서비스 시간.	// + 남은 서비스시간
	int startTime;		// 시작 시각.
	int endTime;		// 종료 시각
} SimCustomer;

typedef struct DequeNodeType
{
	SimCustomer data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;	// ���� ������ ����
	DequeNode* pFrontNode;		// Front ����� ������
	DequeNode* pRearNode;		// Rear ����� ������
} LinkedDeque;

void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pDeque);
void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque);
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque);
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, \
	int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitDequeStatus(int currentTime, LinkedDeque *pWaitDeque);
void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime, int currentTime);

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif


#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif