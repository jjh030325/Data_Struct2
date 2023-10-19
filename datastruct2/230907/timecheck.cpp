/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

int arr[10000000];
BinarySearchTreeNode *root = NULL;             //Ʈ����� ����
clock_t start1, start2, end1, end2;

void Linear_input(int n)
{
	//�迭�� ������ ������ ����
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()*rand();
	}
	end1 = clock();
	printf("%d�� �Է��ϴ� �ð� = %.8f\n", n, (float)(end1 - start1) / CLOCKS_PER_SEC);
}

void Linear_search(int n, int finddata)
{
	float timeAvarge = 0;
	start1 = clock();
	for (int i = 0; i < 100; i++)
	{
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

void BST_input(int n)
{
	//BST�� ������ ������ ����
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		root = insert(root, rand()*rand());
	}
	end1 = clock();
	printf("%d�� �Է��ϴ� �ð� = %.8f\n", n, (float)(end1 - start1) / CLOCKS_PER_SEC);
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
	if (node != NULL)                             //�ֳ� ���� üũ
	{
		printf("�߰�\n");
	}
}

void BST_search(int n, int finddata)
{
	float timeAvarge = 0;
	start1 = clock();
	for (int i = 0; i < 100000; i++)
	{
		search_bst(root, finddata);
	}
	end1 = clock();
	timeAvarge = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Ž���� �ɸ��� �ð��� ��� : %.8f\n", timeAvarge / 100000);
}

int main()
{
	int finddata;
	srand((unsigned int)time(NULL));

	//A. Linear Search
	for (int n = 500000; n <= 10000000; n += 500000)
	{
		Linear_input(n);
		finddata = rand()*rand();
		Linear_search(n, finddata);
	}
	//B. BST
	for (int n = 500000; n <= 10000000; n += 500000)
	{
		BST_input(n);
		resetBST();
		finddata = rand()*rand();
		BST_search(n, finddata);
	}
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
