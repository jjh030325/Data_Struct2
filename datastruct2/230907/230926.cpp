/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[1001] = { false, };       //1���� 1000 ���� �ߺ� üũ�� �迭
int last = 0;
int level = 0;

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

// ť ������ ���� ����ü ����
struct QueueNode {
	struct BinarySearchTreeNode* data;
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

// ť���� ��� ����
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

// ���� ��ȸ �Լ�
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
		if (p->data > n && p->left != NULL)           //�� �� �ִ� ���� ������
		{
			nowlevel++;                               //������ �� �� ���� ����
			p = p->left;
		}
		else if (p->data < n && p->right != NULL)     //�� �� �ִ� ������ ������
		{
			nowlevel++;
			p = p->right;
		}
		else if (p->data == n)                         //�̹� �ִ� ��� ����
		{
			return node;
		}
		else
		{
			if (p->data > n)                          //���̻� �� ���� ���� ��� ��� �߰��� �̾���
			{
				p->left = newNode;
				if (nowlevel > level)                 //���̻� �� �� ���� ��, �ְ����̸� ��������
				{
					level = nowlevel;
				}
				return node;
			}
			else if (p->data < n)                     //���̻� �� ���� ���� ��� ��� �߰��� �̾���
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

// �ݺ����� Ž�� �Լ�
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
	if (node != NULL)                             //�ֳ� ���� üũ
	{
		printf("Ž���� Ƚ�� : %d\n", level);
	}
	else
	{
		printf("%d�� ã������ ��尡 �����ϴ�.", level);
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
			input = rand() % 1000 + 1;            //1���� 100����
			if (data_check[input] == false)      //���� �� ���� ���
			{
				data_check[input] = true;        //���Դٰ� üũ �� ��������
				break;
			}
		}
		root = insert(root, input);              //������
	}
	return root;
}

int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //Ʈ����� ����
	BinarySearchTreeNode *root2 = NULL;             //Ʈ����� ����
	int n;

	n = 10;
	root = randomTree_BST(root, n);
	
	inorder(root);
	printf("\nƮ���� ���� = %d\n", level);

	last = rand() % 2000 + 1;

	printf("������ = %d\n", last);
	search_level(root, last, 0);

	return 0;
}
*/