/*
#define _CRT_SECURE_NO_WARNiNGS_
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode *llink;      //앞의 주소
	struct DListNode *rlink;      //뒤의 주소
}DListNode;
DListNode* DLLInsert_first(DListNode* head, int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));

	if (!newNode)                 //에러케이스
	{
		printf("Memory Error\n");
		return head;
	}
	newNode->data = data;         //값 입력
	if (head == NULL)             //노드가 없는 경우
	{
		newNode->llink = NULL;
		newNode->rlink = NULL;
		head = newNode;           //헤드변경
	}
	else                          //뒤에 노드가 있는 경우
	{
		newNode->llink = NULL;
		newNode->rlink = head;    //새 노드의 오른쪽에 헤드주소를 넣음
		head->llink = newNode;    //헤드 앞에 새 노드를 위치함
		head = newNode;           //가장 앞인 새 노드를 헤드로 변경
	}
	return head;
}

DListNode* DLLInsert_last(DListNode* head, int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p;
	newNode->data = data;         //데이터 입력
	if (!newNode)                 //에러케이스
	{
		printf("Memory Error\n");
		return head;
	}

	if (head == NULL)             //노드가 없는 경우
	{
		newNode->llink = NULL;
		newNode->rlink = NULL;
		head = newNode;
		return head;
	}

	for (p = head; p->rlink != NULL; p = p->rlink)  //마지막 노드 결정
	{
		newNode->llink = p;        //새 노드의 왼쪽 주소 갱신 : 최종으로 마지막값이 넣어짐
	}
	newNode->rlink = NULL;         //마지막 노드이므로 새 노드의 오른쪽은 NULL
	p->rlink = newNode;            //기존의 마지막 노드의 오른쪽에 새 노드를 연결
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
	if (position == 1) {                       //첫번째 삭제
		if ((*h) == NULL)                      //헤드가 비어있는 경우
		{
			printf("지울게없음\n");
		}
		else if ((*h)->rlink == NULL)          //헤드만 있는 경우
		{
			(*h) = NULL;
		}
		else                                   //뒤에 노드가 더 있는 경우
		{
			del = del->rlink->llink;
			(*h) = del->rlink;
			del->rlink->llink = (*h);
			free(del);
		}
		return;
	}
	temp = *h;
	while ((k < position) && temp->rlink != NULL) {  //해당 위치 찾기
		temp = temp->rlink;
		k++;
	}
	if (temp->rlink == NULL) {                  //마지막 노드 삭제
		temp->llink->rlink = NULL;
		free(temp);
	}
	else {                                      //중간 노드 삭제
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

	DLLInsert(h, 1, 10);	print_dlist(head);    //1,2,3,4 순서대로 입력
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