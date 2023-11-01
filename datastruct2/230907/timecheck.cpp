/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

typedef struct AVLTreeNode {
	int data;
	struct AVLTreeNode* left, *right;
	int height;
} AVLTreeNode;

int arr[10000000];
BinarySearchTreeNode *root = NULL;             //Ʈ����� ����
AVLTreeNode *AVLroot = NULL;
clock_t start1, start2, end1, end2;
float timecheck = 0;

void Linear_input(int n)
{
	//�迭�� ������ ������ ����
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()*rand();
	}
	end1 = clock();
	printf("%d�� �Է��ϴ� �ð� = %.8f			", n, (float)(end1 - start1) / CLOCKS_PER_SEC);
}

void Linear_search(int n)
{
	float timeAvarge = 0;
	int finddata;
	start1 = clock();
	for (int i = 0; i < 100; i++)
	{
		finddata = rand()*rand();
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == finddata)            //ã�Ƴ�
			{
				break;
			}
		}
	}
	end1 = clock();
	timeAvarge = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Ž���� �ɸ��� �ð��� ��� : %.8f\n", timeAvarge / 100);
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

void freeBST(BinarySearchTreeNode *node) {
	if (node == NULL) {
		return;
	}
	freeBST(node->left);
	freeBST(node->right);
	free(node);
}

// BST�� �ʱ�ȭ�ϴ� �Լ�
void resetBST() {
	freeBST(root);
	root = NULL; // ��Ʈ ��带 NULL�� �����Ͽ� Ʈ���� �ʱ�ȭ�մϴ�.
}

void BST_input(int t)
{
	//BST�� ������ ������ ����
	start1 = clock();
	for (int i = t - 500000; i < t; i++)
	{
		root = insert(root, arr[i]);
	}
	end1 = clock();
	timecheck += (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("%d�� �Է��ϴ� �ð� = %.8f			", t, timecheck);
}

void search_bst(BinarySearchTreeNode *node, int key)
{
	while (node != NULL) {
		if (key == node->data) break;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
}

void BST_search(int n)
{
	float timeAvarge = 0;
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		int finddata = rand()*rand();
		search_bst(root, finddata);
	}
	end1 = clock();
	timeAvarge = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Ž���� �ɸ��� �ð��� ��� : %.8f\n", timeAvarge / 100000);
}

int Height(AVLTreeNode* root) {
	if (!root) return -1;
	else return root->height;
}

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
AVLTreeNode* newNode(int item) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->data = item;
	newNode->height = 0; // ���� �ʱ�ȭ
	newNode->left = newNode->right = NULL;
	return newNode;
}

// �ܼ�ȸ��(LL)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // new root node;
}

// �ܼ�ȸ��(RR)
AVLTreeNode* SingleRotateRight(AVLTreeNode* W)
{
	AVLTreeNode* X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	return X; // new root node;
}


AVLTreeNode* insert_node(AVLTreeNode* root, int key) {
	if (root == NULL) return newNode(key);

	if (root->data == key) { // �����Ͱ� �ߺ��� ���
		return root;
	}

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// �ڱ� �ڽ��� ���� ����
	root->height = max(Height(root->left), Height(root->right)) + 1;
	// ���� ����(Balance üũ)
	int balance = Height(root->left) - Height(root->right);

	// LL ��Ȳ
	if (balance > 1 && root->left != NULL && key < root->left->data) {
		return SingleRotateLeft(root);
	}

	// RR ��Ȳ
	if (balance < -1 && root->right != NULL && key > root->right->data) {
		return SingleRotateRight(root);
	}

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}

//��ȯ���� Ž�� �Լ�
AVLTreeNode* search(AVLTreeNode* node, int key) {
	if (node == NULL) {
		return NULL;
	}
	if (key == node->data) {
		return node; // (1)
	}
	else if (key < node->data)
		return search(node->left, key); // (2)
	else
		return search(node->right, key); // (3)
}

void freeAVL(BinarySearchTreeNode *node) {
	if (node == NULL) {
		return;
	}
	freeAVL(node->left);
	freeAVL(node->right);
	free(node);
}

// BST�� �ʱ�ȭ�ϴ� �Լ�
void resetAVL() {
	freeAVL(root);
	root = NULL; // ��Ʈ ��带 NULL�� �����Ͽ� Ʈ���� �ʱ�ȭ�մϴ�.
}

void AVL_input(int t)
{
	//AVL�� ������ ������ ����
	start1 = clock();
	for (int i = t - 500000; i < t; i++)
	{
		AVLroot = insert_node(AVLroot, arr[i]);
	}
	end1 = clock();
	timecheck += (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("%d�� �Է��ϴ� �ð� = %.8f			", t, timecheck);
}

void search_avl(AVLTreeNode *node, int key)
{
	while (node != NULL) {
		if (key == node->data) break;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
}

void AVL_search(int n)
{
	float timeAvarge = 0;
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		int finddata = rand()*rand();
		search_avl(AVLroot, finddata);
	}
	end1 = clock();
	timeAvarge = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Ž���� �ɸ��� �ð��� ��� : %.8f\n", timeAvarge / 100000);
}

void DeleteAVLTree(AVLTreeNode* root) {
	if (root == NULL) return;

	DeleteAVLTree(root->left);
	DeleteAVLTree(root->right);

	free(root);
}

int main()
{
	srand((unsigned int)time(NULL));

	//A. Linear Search
	printf("Linear Search\n");
	for (int n = 500000; n <= 10000000; n += 500000)
	{
		Linear_input(n);
		Linear_search(n);
	}
	timecheck = 0;
	//B. BST
	printf("BST Search\n");
	for (int n = 500000; n <= 10000000; n += 500000)
	{
		BST_input(n);
		BST_search(100000);
	}
	resetBST();
	timecheck = 0;
	//C, AVL
	printf("AVL Search\n");
	for (int n = 500000; n <= 10000000; n += 500000)
	{
		AVL_input(n);
		AVL_search(100000);
	}
	resetAVL();
	return 0;
}
*/
/*
0. n���� ������ ������ �߻��Ͽ� �迭�� ���� (��, ������ ������ ������ rand()*rand() �̴�.)

A. Linear Search
1. 0������ ������ n���� ������ ������ �迭�� �����ϴ� �ð� ����
2. �������� �����ϰ� �̸� 1������ ������ �迭���� ã�� �ð��� ���� (100�� �ݺ��Ͽ� ����� ����)
3. �� ������ n�� 500,000���� 500,000�� ������Ű�鼭 10,000,000�� ���� �ݺ�

B. BST
1. 0������ ������ n���� ������ ������ BST�� �����ϴ� �ð� ����
2. �������� �����ϰ� �̸� 1������ ������ BST���� ã�� �ð��� ���� (100,000�� �ݺ��Ͽ� ����� ����)
3. n�� 500,000���� 500,000�� ������Ű�鼭 10,000,000�� ���� �÷����� ����/Ž�� �ð� ����

C. AVL
B�� ������ �����ϰ� �ϵ� BST��� AVL Ʈ���� �����
*/
