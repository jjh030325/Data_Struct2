/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

// AVL 노드 구조체 정의
typedef struct AVLTreeNode {
	int data;
	struct AVLTreeNode* left;
	struct AVLTreeNode* right;
	int height;
} AVLN;

// 큐 구현을 위한 구조체 정의
struct QueueNode {
	struct AVLTreeNode* data;
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
void enqueue(struct Queue* queue, struct AVLTreeNode* data) {
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
struct AVLTreeNode* dequeue(struct Queue* queue) {
	if (queue->front == NULL)
		return NULL;

	struct AVLTreeNode* data = queue->front->data;
	struct QueueNode* temp = queue->front;

	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;

	free(temp);
	return data;
}

// 노드의 높이를 반환하는 함수
int Height(AVLTreeNode* root) {
	if (!root) return 0;
	else return root->height;
}

// 단일 회전 함수: 왼쪽으로 회전 (LL 회전)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // 새로운 루트 노드
}

// 단일 회전 함수: 오른쪽으로 회전 (RR 회전)
AVLTreeNode* SingleRotateRight(AVLTreeNode* X)
{
	AVLTreeNode* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // 새로운 루트 노드
}

//LR
AVLTreeNode* DoubleRotateLeftRight(AVLTreeNode* Z) {
	Z->left = SingleRotateLeft(Z->left);
	return SingleRotateRight(Z);
}

//RL
AVLTreeNode* DoubleRotateRightLeft(AVLTreeNode* X) {
	X->right = SingleRotateLeft(X->right);
	return SingleRotateRight(X);
}

void inorder(AVLTreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

// AVL 트리에 노드를 삽입하는 함수
AVLTreeNode* InsertNode(AVLTreeNode* root, int data)
{
	if (!root) {
		//가장 아래로 내려온 경우
		AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		newNode->height = 0;
		return newNode;
	}

	// 노드 위치로 이동하기
	if (data < root->data) {
		root->left = InsertNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = InsertNode(root->right, data);
	}
	else {
		// 이미 존재하는 값
		return root;
	}

	// 높이 업데이트
	root->height = max(Height(root->left), Height(root->right)) + 1;

	// 균형 검사 및 균형 잡기
	int balance = Height(root->left) - Height(root->right);

	// LL 회전
	if (balance >= 1 && data < root->left->data) 
	{
		printf("[LL 위반 발생]");
		return SingleRotateLeft(root);
	}
	// RR 회전
	if (balance <= -1 && data > root->right->data) 
	{
		printf("[RR 위반 발생]");
		return SingleRotateRight(root);
	}
	// LR 회전
	if (balance >= 1 && data > root->left->data)
	{
		printf("[LR 위반 발생]");
		return DoubleRotateLeftRight(root);
	}
	// RL 회전
	if (balance <= -1 && data < root->right->data)
	{
		printf("[RL 위반 발생]");
		return DoubleRotateRightLeft(root);
	}

	return root;
}

AVLTreeNode* printAndinsert(AVLTreeNode* root, int n)
{
	printf("input : %d ", n);
	root = InsertNode(root, n);
	printf("\n");
	return root;
}

// 레벨 순회 함수
void levelOrder(struct AVLTreeNode* root) {
	if (root == NULL)
		return;

	struct Queue* queue = createQueue();
	enqueue(queue, root);

	while (queue->front != NULL) {
		struct AVLTreeNode* current = dequeue(queue);
		printf("%d ", current->data);

		if (current->left != NULL)
			enqueue(queue, current->left);

		if (current->right != NULL)
			enqueue(queue, current->right);
	}

	free(queue);
}

int main()
{
	AVLN* root = NULL;

	root = printAndinsert(root, 6);
	root = printAndinsert(root, 2);
	root = printAndinsert(root, 9);
	root = printAndinsert(root, 1);
	root = printAndinsert(root, 0);
	root = printAndinsert(root, 10);
	root = printAndinsert(root, 15);

	printf("level\n");
	levelOrder(root);
	printf("\nin\n");
	inorder(root);
}
*/