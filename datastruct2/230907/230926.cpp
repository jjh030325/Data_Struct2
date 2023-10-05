/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[1001] = { false, };       //1에서 1000 사이 중복 체크용 배열
int last = 0;
int level = 0;

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

// 큐 구현을 위한 구조체 정의
struct QueueNode {
	struct BinarySearchTreeNode* data;
	struct QueueNode* next;
};

// 큐 구조체 정의
struct Queue {
	struct QueueNode* front;
	struct QueueNode* rear;
};

// 큐 초기화
struct Queue* createQueue() {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

// 큐에 요소 추가
void enqueue(struct Queue* queue, struct BinarySearchTreeNode* data) {
	struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->rear == NULL) {
		queue->front = queue->rear = newNode;
		return;
	}

	queue->rear->next = newNode;
	queue->rear = newNode;
}

// 큐에서 요소 제거
struct BinarySearchTreeNode* dequeue(struct Queue* queue) {
	if (queue->front == NULL)
		return NULL;

	struct BinarySearchTreeNode* data = queue->front->data;
	struct QueueNode* temp = queue->front;

	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;

	free(temp);
	return data;
}

// 레벨 순회 함수
void levelOrder(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return;

	struct Queue* queue = createQueue();
	enqueue(queue, root);

	while (queue->front != NULL) {
		struct BinarySearchTreeNode* current = dequeue(queue);
		printf("%d ", current->data);

		if (current->left != NULL)
			enqueue(queue, current->left);

		if (current->right != NULL)
			enqueue(queue, current->right);
	}

	free(queue);
}


BinarySearchTreeNode* insert(BinarySearchTreeNode *node, int n)
{
	int nowlevel = 1;
	BinarySearchTreeNode* newNode = (BinarySearchTreeNode *)malloc(sizeof(BinarySearchTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = n;
	BinarySearchTreeNode *p = node;
	if (node == NULL)
	{
		return newNode;
	}

	while (1)
	{
		if (p->data > n && p->left != NULL)           //갈 수 있는 왼쪽 끝으로
		{
			nowlevel++;                               //내려갈 때 현 레벨 증가
			p = p->left;
		}
		else if (p->data < n && p->right != NULL)     //갈 수 있는 오른쪽 끝으로
		{
			nowlevel++;
			p = p->right;
		}
		else if (p->data == n)                         //이미 있는 경우 리턴
		{
			return node;
		}
		else
		{
			if (p->data > n)                          //더이상 갈 곳이 없는 경우 노드 추가로 이어줌
			{
				p->left = newNode;
				if (nowlevel > level)                 //더이상 갈 수 없을 때, 최고레벨이면 갱신해줌
				{
					level = nowlevel;
				}
				return node;
			}
			else if (p->data < n)                     //더이상 갈 곳이 없는 경우 노드 추가로 이어줌
			{
				if (nowlevel > level)
				{
					level = nowlevel;
				}
				p->right = newNode;
				return node;
			}
		}
	}
}

// 반복적인 탐색 함수
void search_level(BinarySearchTreeNode *node, int key, int level)
{
	while (node != NULL) {
		if (key == node->data) break;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
		level++;
	}
	if (node != NULL)                             //있나 없나 체크
	{
		printf("탐색의 횟수 : %d\n", level);
	}
	else
	{
		printf("%d번 찾았으나 노드가 없습니다.", level);
	}
}

int FindMin(BinarySearchTreeNode *node)
{
	while (node->left != NULL)
		node = node->left;
	return node->data;
}
int FindMax(BinarySearchTreeNode *node)
{
	while (node->right != NULL)
		node = node->right;
	return node->data;
}

void inorder(BinarySearchTreeNode *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

BinarySearchTreeNode *randomTree_BST(BinarySearchTreeNode *root, int n)
{
	int input;

	for (int i = 1; i <= n; i++)
	{
		while (1)
		{
			input = rand() % 1000 + 1;            //1에서 100사이
			if (data_check[input] == false)      //나온 적 없는 경우
			{
				data_check[input] = true;        //나왔다고 체크 후 빠져나옴
				break;
			}
		}
		root = insert(root, input);              //노드삽입
	}
	return root;
}

int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //트리노드 선언
	BinarySearchTreeNode *root2 = NULL;             //트리노드 선언
	int n;

	n = 10;
	root = randomTree_BST(root, n);
	
	inorder(root);
	printf("\n트리의 레벨 = %d\n", level);

	last = rand() % 2000 + 1;

	printf("랜덤값 = %d\n", last);
	search_level(root, last, 0);

	return 0;
}
*/