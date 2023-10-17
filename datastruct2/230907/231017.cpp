/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

// AVL ��� ����ü ����
typedef struct AVLTreeNode {
	int data;
	struct AVLTreeNode* left;
	struct AVLTreeNode* right;
	int height;
} AVLN;

// ť ������ ���� ����ü ����
struct QueueNode {
	struct AVLTreeNode* data;
	struct QueueNode* next;
};

// ť ����ü ����
struct Queue {
	struct QueueNode* front;
	struct QueueNode* rear;
};

// ť �ʱ�ȭ
struct Queue* createQueue() {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

// ť�� ��� �߰�
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

// ť���� ��� ����
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

// ����� ���̸� ��ȯ�ϴ� �Լ�
int Height(AVLTreeNode* root) {
	if (!root) return 0;
	else return root->height;
}

// ���� ȸ�� �Լ�: �������� ȸ�� (LL ȸ��)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // ���ο� ��Ʈ ���
}

// ���� ȸ�� �Լ�: ���������� ȸ�� (RR ȸ��)
AVLTreeNode* SingleRotateRight(AVLTreeNode* X)
{
	AVLTreeNode* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // ���ο� ��Ʈ ���
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

// AVL Ʈ���� ��带 �����ϴ� �Լ�
AVLTreeNode* InsertNode(AVLTreeNode* root, int data)
{
	if (!root) {
		//���� �Ʒ��� ������ ���
		AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		newNode->height = 0;
		return newNode;
	}

	// ��� ��ġ�� �̵��ϱ�
	if (data < root->data) {
		root->left = InsertNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = InsertNode(root->right, data);
	}
	else {
		// �̹� �����ϴ� ��
		return root;
	}

	// ���� ������Ʈ
	root->height = max(Height(root->left), Height(root->right)) + 1;

	// ���� �˻� �� ���� ���
	int balance = Height(root->left) - Height(root->right);

	// LL ȸ��
	if (balance >= 1 && data < root->left->data) 
	{
		printf("[LL ���� �߻�]");
		return SingleRotateLeft(root);
	}
	// RR ȸ��
	if (balance <= -1 && data > root->right->data) 
	{
		printf("[RR ���� �߻�]");
		return SingleRotateRight(root);
	}
	// LR ȸ��
	if (balance >= 1 && data > root->left->data)
	{
		printf("[LR ���� �߻�]");
		return DoubleRotateLeftRight(root);
	}
	// RL ȸ��
	if (balance <= -1 && data < root->right->data)
	{
		printf("[RL ���� �߻�]");
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

// ���� ��ȸ �Լ�
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