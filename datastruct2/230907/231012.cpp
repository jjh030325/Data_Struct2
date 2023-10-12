/*#define _CRT_SECURE_NO_WARNINGS
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

// 노드의 높이를 반환하는 함수
int Height(AVLN* root)
{
	if (!root) return -1;
	else return root->height;
}

// 단일 회전 함수: 왼쪽으로 회전 (LL 회전)
AVLN* SingleRotateLeft(AVLN* X)
{
	AVLN* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // 새로운 루트 노드
}

// 단일 회전 함수: 오른쪽으로 회전 (RR 회전)
AVLN* SingleRotateRight(AVLN* X)
{
	AVLN* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // 새로운 루트 노드
}

// AVL 트리에 노드를 삽입하는 함수
AVLN* InsertNode(AVLN* root, int data)
{
	if (!root) {
		//가장 아래로 내려온 경우
		AVLN* newNode = (AVLN*)malloc(sizeof(AVLN));
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
	if (balance > 1 && data < root->left->data) {
		printf("[LL 위반 발생]");
		return SingleRotateLeft(root);
	}
	// RR 회전
	if (balance < -1 && data > root->right->data) {
		printf("[RR 위반 발생]");
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