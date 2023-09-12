/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element; // �������� �ڷ���

typedef struct stackNode {
	int data;
	struct stackNode* link;
} stackNode;
void push(stackNode** top, element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));    //����� �ȳѾ�ٸ� ��� �߰�
	if (!temp)
		exit(1);
	temp->data = item;
	temp->link = *top;
	*top = temp;
	//printf("%c", temp->data);                                  //�Է��� �ߴٴ� ���� ǥ���ϱ� ���� printf
}
stackNode* createStack()                                        //���� ����
{
	stackNode* p = NULL;
	return p;
}
void printStack(stackNode** top)                                //���� ������� ����ϰ�, element�� ���� ����ϴ� �Լ�
{
	int n = 0;                                                  //����üũ�� ����
	for (stackNode* p = *top; p != NULL; p = p->link)
	{
		n++;
		printf("%d ", p->data);
	}
	printf("\n");
	printf("element�� ���� : %d\n", n);
}
element peek(stackNode** top)                                   //���� ���� ���� �ִ� �� ����ϴ� �Լ�
{
	stackNode* p = *top;
	return p->data;
}
element pop(stackNode** top)                                    //���� ���� ���� �����ϸ鼭 ����ϴ� �Լ�
{
	stackNode* p = *top;
	if (p == NULL)                                              //������ �� ���
		exit(1);
	*top = p->link;                                             //top�� ������ �ι�°�� �Ű���
	element data = p->data;                                     //������ ���� ������
	free(p);                                                    //���� �� ���� ù ��� ����
	return data;                                                //������ ����
}
void deleteStack(stackNode** top)                               //���� ���� �Լ�
{
	stackNode* p = *top;                                        //�����Ͱ� �ϳ���� �Űܴٴϸ鼭 ������ �Ұ���
	stackNode* pp;                                              //������ ���� ������ ���� �ϳ� �߰�
	while (p != NULL)
	{
		pp = p;                                                 //������ ��ġ �ּ� ����
		p = p->link;                                            //����ĭ �̵�
		free(pp);                                               //����
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
	Q->capacity = size; // Queue ũ��
	Q->front = Q->rear = -1; //front, rear �ʱ갪 ����
	Q->array = (int *)malloc(Q->capacity * sizeof(element));
	if (!Q->array)
		return NULL;
	return Q;
}
// ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(QueueType *Q) {
	return((Q->front) == -1);
}
// ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType *Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}
//ť ���� ����
void deleteQueue(QueueType* Q) {
	if (Q) {
		if (Q->array)
			free(Q->array);
	}
	free(Q);
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType *Q, element item) {
	if (isFull(Q)) {
		printf("Queue Overflow\n");
	}
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;
		if (Q->front == -1)
			Q->front = Q->rear; // ù �������� ��� f=r=0 �̵Ǿ�� ��
	}
}
//���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
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
	if (Q->front <= Q->rear)                           //front�� rear ������ ��� = front���� rear + 1���� ���
	{
		for (int i = Q->front; i < Q->rear + 1; i++)
		{
			printf("%d | ", Q->array[i]);
		}
		printf("\n");
	}
	else                                               //�ƴѰ�� = front���� ���������� ��� �� 0���� rear + 1���� ���
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
	srand(time(NULL)); // ���� �ʱ�ȭ
	int n, r, q;
	stackNode *top;
	QueueType *Q;

	scanf("%d", &n);
	top = createStack();
	Q = Queue(n + 1);                         //ť�� ����� �Է¹޾� ����

	for (int i = 0; i <= n; i++)
	{
		r = rand() % 9; // ���� ����
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