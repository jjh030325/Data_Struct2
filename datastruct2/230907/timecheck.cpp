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
BinarySearchTreeNode *root = NULL;             //트리노드 선언
AVLTreeNode *AVLroot = NULL;
clock_t start1, start2, end1, end2;
float timecheck = 0;

void Linear_input(int n)
{
	//배열에 랜덤한 정수를 삽입
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()*rand();
	}
	end1 = clock();
	printf("%d번 입력하는 시간 = %.8f			", n, (float)(end1 - start1) / CLOCKS_PER_SEC);
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
			if (arr[j] == finddata)            //찾아냄
			{
				break;
			}
		}
	}
	end1 = clock();
	timeAvarge = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("탐색에 걸리는 시간의 평균 : %.8f\n", timeAvarge / 100);
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
		if (p->data > n && p->left != NULL)           //갈 수 있는 왼쪽 끝으로
		{
			p = p->left;
		}
		else if (p->data < n && p->right != NULL)     //갈 수 있는 오른쪽 끝으로
		{
			p = p->right;
		}
		else if (p->data == n)                         //이미 있는 경우 리턴
		{
			return node;
		}
		else
		{
			if (p->data > n)                          //더이상 갈 곳이 없는 경우 노드 추가로 이어줌
			{
				p->left = newNode;
				return node;
			}
			else if (p->data < n)                     //더이상 갈 곳이 없는 경우 노드 추가로 이어줌
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

// BST를 초기화하는 함수
void resetBST() {
	freeBST(root);
	root = NULL; // 루트 노드를 NULL로 설정하여 트리를 초기화합니다.
}

void BST_input(int t)
{
	//BST에 랜덤한 정수를 삽입
	start1 = clock();
	for (int i = t - 500000; i < t; i++)
	{
		root = insert(root, arr[i]);
	}
	end1 = clock();
	timecheck += (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("%d번 입력하는 시간 = %.8f			", t, timecheck);
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
	printf("탐색에 걸리는 시간의 평균 : %.8f\n", timeAvarge / 100000);
}

int Height(AVLTreeNode* root) {
	if (!root) return -1;
	else return root->height;
}

// 새로운 노드를 생성하고 초기화합니다.
AVLTreeNode* newNode(int item) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("메모리 오류");
		exit(1);
	}
	newNode->data = item;
	newNode->height = 0; // 높이 초기화
	newNode->left = newNode->right = NULL;
	return newNode;
}

// 단순회전(LL)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // new root node;
}

// 단순회전(RR)
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

	if (root->data == key) { // 데이터가 중복일 경우
		return root;
	}

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// 자기 자신의 높이 갱신
	root->height = max(Height(root->left), Height(root->right)) + 1;
	// 균형 유지(Balance 체크)
	int balance = Height(root->left) - Height(root->right);

	// LL 상황
	if (balance > 1 && root->left != NULL && key < root->left->data) {
		return SingleRotateLeft(root);
	}

	// RR 상황
	if (balance < -1 && root->right != NULL && key > root->right->data) {
		return SingleRotateRight(root);
	}

	// 변환된 루트 포인터를 반환
	return root;
}

//순환적인 탐색 함수
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

// BST를 초기화하는 함수
void resetAVL() {
	freeAVL(root);
	root = NULL; // 루트 노드를 NULL로 설정하여 트리를 초기화합니다.
}

void AVL_input(int t)
{
	//AVL에 랜덤한 정수를 삽입
	start1 = clock();
	for (int i = t - 500000; i < t; i++)
	{
		AVLroot = insert_node(AVLroot, arr[i]);
	}
	end1 = clock();
	timecheck += (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("%d번 입력하는 시간 = %.8f			", t, timecheck);
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
	printf("탐색에 걸리는 시간의 평균 : %.8f\n", timeAvarge / 100000);
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
0. n개의 랜덤한 정수를 발생하여 배열에 저장 (단, 랜덤한 정수의 범위는 rand()*rand() 이다.)

A. Linear Search
1. 0번에서 생성한 n개의 랜덤한 정수를 배열에 삽입하는 시간 측정
2. 랜덤값을 선택하고 이를 1번에서 생성한 배열에서 찾는 시간을 구함 (100번 반복하여 평균을 구함)
3. 위 실험을 n이 500,000부터 500,000씩 증가시키면서 10,000,000개 까지 반복

B. BST
1. 0번에서 생성한 n개의 랜덤한 정수를 BST에 삽입하는 시간 측정
2. 랜덤값을 선택하고 이를 1번에서 생성한 BST에서 찾는 시간을 구함 (100,000번 반복하여 평균을 구함)
3. n을 500,000부터 500,000씩 증가시키면서 10,000,000개 까지 늘려가며 삽입/탐색 시간 측정

C. AVL
B의 과정과 동일하게 하되 BST대신 AVL 트리를 사용함
*/
