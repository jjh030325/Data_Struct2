/*#define _CRT_SECURE_NO_WARNINGS
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

// ����� ���̸� ��ȯ�ϴ� �Լ�
int Height(AVLN* root)
{
	if (!root) return -1;
	else return root->height;
}

// ���� ȸ�� �Լ�: �������� ȸ�� (LL ȸ��)
AVLN* SingleRotateLeft(AVLN* X)
{
	AVLN* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // ���ο� ��Ʈ ���
}

// ���� ȸ�� �Լ�: ���������� ȸ�� (RR ȸ��)
AVLN* SingleRotateRight(AVLN* X)
{
	AVLN* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // ���ο� ��Ʈ ���
}

// AVL Ʈ���� ��带 �����ϴ� �Լ�
AVLN* InsertNode(AVLN* root, int data)
{
	if (!root) {
		//���� �Ʒ��� ������ ���
		AVLN* newNode = (AVLN*)malloc(sizeof(AVLN));
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
	if (balance > 1 && data < root->left->data) {
		printf("[LL ���� �߻�]");
		return SingleRotateLeft(root);
	}
	// RR ȸ��
	if (balance < -1 && data > root->right->data) {
		printf("[RR ���� �߻�]");
		return SingleRotateRight(root);
	}

	return root;
}

void inorder(AVLN* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

AVLN* printAndinsert(AVLN* root, int n)
{
	printf("input : %d ", n);
	root = InsertNode(root, n);
	printf("\n");
	return root;
}

int main()
{
	AVLN* root = NULL;

	root = printAndinsert(root, 6);
	root = printAndinsert(root, 2);
	root = printAndinsert(root, 9);
	root = printAndinsert(root, 1);
	root = printAndinsert(root, 8);
	root = printAndinsert(root, 0);

	inorder(root);

	return 0;
}
*/