/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[1001] = { false, };       //1���� 1000 ���� �ߺ� üũ�� �迭
int case_check = 0;

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

BinarySearchTreeNode* FindMax(BinarySearchTreeNode *node)
{
	while (node->right != NULL)
		node = node->right;
	return node;
}

BinarySearchTreeNode* FindMin(BinarySearchTreeNode *node)
{
	while (node->left != NULL)
		node = node->left;
	return node;
}

BinarySearchTreeNode* deleteBSTN(BinarySearchTreeNode* root, int data)
{
	BinarySearchTreeNode* temp;
	//data�� ��ġ �˻�
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (data < root->data)
		root->left = deleteBSTN(root->left, data);
	else if (data > root->data)
		root->right = deleteBSTN(root->right, data);	//data�� ã�� ���
	else {
		//�ڽ��� 2���� ��� ������ ����Ʈ���� �ּڰ��� ��ü�Ѵ�. (������ �ݴ��)
		if (root->left && root->right) {
			temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deleteBSTN(root->right, root->data);
			case_check = 3;
		}
		else { //�ڽ��� �ϳ� �Ǵ� ���� ���
			temp = root;
			if (root->left == NULL)            //�ϳ��� ����Ʈ�� �ִ� ���
			{
				root = root->right;
				if (root != NULL)              //��������� ���
				{
					case_check = 1;
				}
				else
				{
					case_check = 2;
				}
			}	
			else if (root->right == NULL)      //������ �ִµ� �������� ����
			{
				root = root->left;
				case_check = 2;
			}
			free(temp);
		}
	}
	return root;
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
			input = rand() % 1000 + 1;            //1���� 1000����
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

int chooseNode()
{
	int input;
	while (1)
	{
		input = rand() % 1000 + 1;            //1���� 100����
		if (data_check[input] == true)
		{
			return input;
		}
	}
	
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


int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //Ʈ����� ����
	int choose;

	root = randomTree_BST(root, 10);

	levelOrder(root);
	choose = chooseNode();                         //��� ����
	root = deleteBSTN(root, choose);
	printf("\n");
	levelOrder(root);
	printf("case %d", case_check);

	return 0;
}
*/