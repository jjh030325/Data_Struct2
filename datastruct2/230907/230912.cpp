/*
#define _CRT_SECURE_NO_WARNiNGS_
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode *llink;      //���� �ּ�
	struct DListNode *rlink;      //���� �ּ�
}DListNode;
DListNode* DLLInsert_first(DListNode* head, int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));

	if (!newNode)                 //�������̽�
	{
		printf("Memory Error\n");
		return head;
	}
	newNode->data = data;         //�� �Է�
	if (head == NULL)             //��尡 ���� ���
	{
		newNode->llink = NULL;
		newNode->rlink = NULL;
		head = newNode;           //��庯��
	}
	else                          //�ڿ� ��尡 �ִ� ���
	{
		newNode->llink = NULL;
		newNode->rlink = head;    //�� ����� �����ʿ� ����ּҸ� ����
		head->llink = newNode;    //��� �տ� �� ��带 ��ġ��
		head = newNode;           //���� ���� �� ��带 ���� ����
	}
	return head;
}

DListNode* DLLInsert_last(DListNode* head, int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p;
	newNode->data = data;         //������ �Է�
	if (!newNode)                 //�������̽�
	{
		printf("Memory Error\n");
		return head;
	}

	if (head == NULL)             //��尡 ���� ���
	{
		newNode->llink = NULL;
		newNode->rlink = NULL;
		head = newNode;
		return head;
	}

	for (p = head; p->rlink != NULL; p = p->rlink)  //������ ��� ����
	{
		newNode->llink = p;        //�� ����� ���� �ּ� ���� : �������� ���������� �־���
	}
	newNode->rlink = NULL;         //������ ����̹Ƿ� �� ����� �������� NULL
	p->rlink = newNode;            //������ ������ ����� �����ʿ� �� ��带 ����
	return head;
}

void print_dlist(DListNode* head)
{
	DListNode *p;
	for (p = head; p != NULL; p = p->rlink)
	{
		printf("<-%d->", p->data);
	}
	printf("\n");
}

void DLLInsert(DListNode** h, int position, int data)
{
	int k = 1;
	DListNode * newNode, *temp;
	newNode = (DListNode*)malloc(sizeof(DListNode));
	newNode->data = data;
	if (position == 1) { // insertion at beginning
		if ((*h) == NULL)
		{
			newNode->llink = NULL;
			newNode->rlink = *h;
			*h = newNode;
		}
		else
		{
			newNode->llink = NULL;
			newNode->rlink = *h;
			(*h)->llink = newNode;
			*h = newNode;
		}
		return;
	}
	temp = *h;
	while ((k < position - 1) && temp->rlink != NULL) {
		temp = temp->rlink;
		k++;
	}
	if (temp->rlink == NULL) {// insert at the end
		newNode->rlink = temp->rlink;
		newNode->llink = temp;
		temp->rlink = newNode;
	}
	else {// insert in the middle
		newNode->rlink = temp->rlink;
		newNode->llink = temp;
		temp->rlink->llink = newNode;
		temp->rlink = newNode;
	}
}

void DLLDelete(DListNode** h, int position)
{
	int k = 1;
	DListNode *del, *temp;
	del = *h;
	if (position == 1) {                       //ù��° ����
		if ((*h) == NULL)                      //��尡 ����ִ� ���
		{
			printf("����Ծ���\n");
		}
		else if ((*h)->rlink == NULL)          //��常 �ִ� ���
		{
			(*h) = NULL;
		}
		else                                   //�ڿ� ��尡 �� �ִ� ���
		{
			del = del->rlink->llink;
			(*h) = del->rlink;
			del->rlink->llink = (*h);
			free(del);
		}
		return;
	}
	temp = *h;
	while ((k < position) && temp->rlink != NULL) {  //�ش� ��ġ ã��
		temp = temp->rlink;
		k++;
	}
	if (temp->rlink == NULL) {                  //������ ��� ����
		temp->llink->rlink = NULL;
		free(temp);
	}
	else {                                      //�߰� ��� ����
		temp->rlink->llink = temp->llink;
		temp->llink->rlink = temp->rlink;
		free(temp);
	}
	return;
}

int main()
{
	DListNode* head = NULL;
	DListNode** h = &head;

	DLLInsert(h, 1, 10);	print_dlist(head);    //1,2,3,4 ������� �Է�
	DLLInsert(h, 2, 20); print_dlist(head);
	DLLInsert(h, 3, 30); print_dlist(head);
	DLLInsert(h, 4, 40); print_dlist(head);
	DLLInsert(h, 5, 50); print_dlist(head);
	DLLInsert(h, 6, 60); print_dlist(head);
	DLLInsert(h, 1, 5); print_dlist(head);

	DLLDelete(h, 1); print_dlist(head);

	return 0;
}
*/