/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[1000];
int sortedArr[1000];

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

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

void sort_arr(int n)
{
	//���ĵ� �迭 ������ֱ�
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (sortedArr[j] > sortedArr[i])
			{
				int tmp = sortedArr[j];
				sortedArr[j] = sortedArr[i];
				sortedArr[i] = tmp;
			}
		}
	}
}

int min_arr(int n)
{
	int m = 50000;
	for (int i = 0; i < n; i++)
	{
		if (m > arr[i])
		{
			m = arr[i];
		}
	}
	return m;
}

BinarySearchTreeNode* FindMin(BinarySearchTreeNode *node)
{
	while (node->left != NULL)
		node = node->left;
	return node;
}

void del_arr(int n)
{
	for (int i = 0; i < 1000; i++)
	{
		if (n == arr[i])
		{
			arr[i] = 50000;
		}
	}
}

void del_sortedArr()
{
	for (int i = 0; i < 999; i++)
	{
		sortedArr[i] = sortedArr[i + 1];
	}
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
		}
		else { //�ڽ��� �ϳ� �Ǵ� ���� ���
			temp = root;
			if (root->left == NULL)            //�ϳ��� ����Ʈ�� �ִ� ���
			{
				root = root->right;
			}
			else if (root->right == NULL)      //������ �ִµ� �������� ����
			{
				root = root->left;
			}
			free(temp);
		}
	}
	return root;
}

int main()
{
	int r;
	BinarySearchTreeNode *root = NULL;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		r = rand() % 10000 + 1;
		arr[i] = r;
		sortedArr[i] = r;
		root = insert(root, r);
	}
	sort_arr(1000);

	for (int i = 0; i < 5; i++)
	{
		printf("���� �ȵ� �迭 �ּҰ� : %d\n", min_arr(1000));
		del_arr(min_arr(1000));
		printf("������ �迭 �ּҰ� : %d\n", sortedArr[0]);
		del_sortedArr();
		printf("BST �ּҰ� : %d\n", FindMin(root)->data);
		root = deleteBSTN(root, FindMin(root)->data);
	}

	return 0;
}
*/

/*
�켱���� ť ������� ���� ���� ã�� ��.
1. �������� �迭
2. ���ĵ� �迭
3. BST

�� 1-10000������ ������ 1000�� ����
*/