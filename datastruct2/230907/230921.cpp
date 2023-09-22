#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[101] = { false, };       //1���� 100 ���� �ߺ� üũ�� �迭

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
			p = p->left;
		}
		else if (p->data < n && p->right != NULL)     //�� �� �ִ� ������ ������
		{
			p = p->right;
		}
		else if(p->data == n)                         //�̹� �ִ� ��� ����
		{
			return node;
		}
		else
		{
			if (p->data > n)                          //���̻� �� ���� ���� ��� ��� �߰��� �̾���
			{
				p->left = newNode;
				return node;
			}
			else if (p->data < n)                     //���̻� �� ���� ���� ��� ��� �߰��� �̾���
			{
				p->right = newNode;
				return node;
			}
		}
	}
}

// �ݺ����� Ž�� �Լ�
BinarySearchTreeNode *search(BinarySearchTreeNode *node, int key)
{
	while (node != NULL) {
		if (key == node->data) return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; // Ž���� �������� ��� NULL ��ȯ
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
			input = rand() % 100 + 1;            //1���� 100����
			if (data_check[input] == false)      //���� �� ���� ���
			{
				data_check[input] = true;        //���Դٰ� üũ �� ��������
				break;
			}
		}
		printf("%d��° ���� = %d\n", i, input);  //���
		root = insert(root, input);              //������
	}
	return root;
}

int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //Ʈ����� ����
	int n;

	scanf("%d", &n);

	root = randomTree_BST(root, n);

	inorder(root);
	printf("\n");
	levelOrder(root);

	return 0;
}

/*
1. BST�� insert �Լ� ����
BST�� �Է��Լ��� �����ϰ�, level order, inorder ������� ����Ͻÿ�.
�Է� ������ {18, 7, 26, 3, 12, 31, 27}

2. ������ BST �����
1~100 ������ ������ ���ڸ� �����Ͽ� BST�� ����ÿ�.
(��, �ߺ��� ���� ���õ��� �ʰ��ϰ�, ����� ������ �Լ��� �Ķ���ͷ� �ް� �Ͻÿ�.)
��) 7���� ���� ������ BST�� ����� �Լ�: root_BST = randomTree_BST(7);
*/