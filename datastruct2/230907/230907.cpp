/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element; // 데이터의 자료형

typedef struct stackNode {
	int data;
	struct stackNode* link;
} stackNode;
void push(stackNode** top, element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));    //사이즈가 안넘어간다면 노드 추가
	if (!temp)
		exit(1);
	temp->data = item;
	temp->link = *top;
	*top = temp;
	//printf("%c", temp->data);                                  //입력을 했다는 것을 표시하기 위한 printf
}
stackNode* createStack()                                        //스택 생성
{
	stackNode* p = NULL;
	return p;
}
void printStack(stackNode** top)                                //스택 순서대로 출력하고, element의 갯수 출력하는 함수
{
	int n = 0;                                                  //갯수체크용 변수
	for (stackNode* p = *top; p != NULL; p = p->link)
	{
		n++;
		printf("%d ", p->data);
	}
	printf("\n");
	printf("element의 갯수 : %d\n", n);
}
element peek(stackNode** top)                                   //스택 가장 위에 있는 값 출력하는 함수
{
	stackNode* p = *top;
	return p->data;
}
element pop(stackNode** top)                                    //가장 위의 값을 삭제하면서 출력하는 함수
{
	stackNode* p = *top;
	if (p == NULL)                                              //스택이 빈 경우
		exit(1);
	*top = p->link;                                             //top을 위에서 두번째로 옮겨줌
	element data = p->data;                                     //데이터 값을 빼내기
	free(p);                                                    //빼낸 후 가장 첫 노드 제거
	return data;                                                //데이터 리턴
}
void deleteStack(stackNode** top)                               //스택 삭제 함수
{
	stackNode* p = *top;                                        //포인터가 하나라면 옮겨다니면서 삭제가 불가능
	stackNode* pp;                                              //삭제를 위해 포인터 변수 하나 추가
	while (p != NULL)
	{
		pp = p;                                                 //삭제할 위치 주소 복사
		p = p->link;                                            //다음칸 이동
		free(pp);                                               //삭제
	}
	*top = NULL;
}
bool Empty_Stack(stackNode** p)
{
	return *p == NULL;
}

typedef struct {
	int front, rear;
	int capacity;
	int *array;
} QueueType;

QueueType *Queue(int size) {
	QueueType *Q;
	Q = (QueueType *)malloc(sizeof(QueueType));
	if (!Q)
		return NULL;
	Q->capacity = size; // Queue 크기
	Q->front = Q->rear = -1; //front, rear 초깃값 설정
	Q->array = (int *)malloc(Q->capacity * sizeof(element));
	if (!Q->array)
		return NULL;
	return Q;
}
// 원형 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType *Q) {
	return((Q->front) == -1);
}
// 원형 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType *Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}
//큐 삭제 연산
void deleteQueue(QueueType* Q) {
	if (Q) {
		if (Q->array)
			free(Q->array);
	}
	free(Q);
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType *Q, element item) {
	if (isFull(Q)) {
		printf("Queue Overflow\n");
	}
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;
		if (Q->front == -1)
			Q->front = Q->rear; // 첫 데이터의 경우 f=r=0 이되어야 함
	}
}
//원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deQueue(QueueType *Q) {
	int data = 0;
	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		exit(1);
	}
	else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else
			Q->front = (Q->front + 1) % Q->capacity;
	}
	return data;
}
void printQueue(QueueType *Q)
{
	if (Q->front <= Q->rear)                           //front가 rear 이하인 경우 = front부터 rear + 1까지 출력
	{
		for (int i = Q->front; i < Q->rear + 1; i++)
		{
			printf("%d | ", Q->array[i]);
		}
		printf("\n");
	}
	else                                               //아닌경우 = front부터 마지막까지 출력 후 0부터 rear + 1까지 출력
	{
		for (int i = Q->front; i < Q->capacity; i++)
		{
			printf("%d | ", Q->array[i]);
		}
		for (int i = 0; i < Q->rear + 1; i++)
		{
			printf("%d | ", Q->array[i]);
		}
		printf("\n");
	}
}

int main()
{
	srand(time(NULL)); // 난수 초기화
	int n, r, q;
	stackNode *top;
	QueueType *Q;

	scanf("%d", &n);
	top = createStack();
	Q = Queue(n + 1);                         //큐의 사이즈를 입력받아 생성

	for (int i = 0; i <= n; i++)
	{
		r = rand() % 9; // 난수 생성
		push(&top, r);
		enQueue(Q, r);
	}

	for (int i = n; i >= 0; i--)
	{
		if (i == 0)
		{
			printf("%d\n", pop(&top));
		}
		else if (peek(&top) == 0)
		{
			pop(&top);
			continue;
		}
		else if (peek(&top) == 1)
		{
			if (i == 1)
			{
				printf("x + ");
			}
			else
			{
				printf("x^%d + ", i);
			}
		}
		else
		{
			if (i == 1)
			{
				printf("%dx + ", pop(&top));
			}
			else
			{
				printf("%dx^%d + ", pop(&top), i);
			}
		}
	}

	for (int i = n; i >= 0; i--)
	{
		q = deQueue(Q);
		if (i == 0)
		{
			printf("%d\n", q);
			break;
		}
		if (q != 0)
		{
			if (q == 1)
			{
				if (i == 1)
				{
					printf("x + ");
				}
				else
				{
					printf("x^%d + ", i);
				}
			}
			else
			{
				if (i == 1)
				{
					printf("%dx + ", q);
				}
				else
				{
					printf("%dx^%d + ", q, i);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
*/