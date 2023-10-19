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
BinarySearchTreeNode *root = NULL;             //트리노드 선언
clock_t start1, start2, end1, end2;

void Linear_input(int n)
{
	//배열에 랜덤한 정수를 삽입
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()*rand();
	}
	end1 = clock();
	printf("%d번 입력하는 시간 = %.8f\n", n, (float)(end1 - start1) / CLOCKS_PER_SEC);
}

void Linear_search(int n, int finddata)
{
	float timeAvarge = 0;
	start1 = clock();
	for (int i = 0; i < 100; i++)
	{
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
		if (p->data > n && p->left != NULL)           //갈 수 있는 왼쪽 끝으로
		{
			nowlevel++;                               //내려갈 때 현 레벨 증가
			p = p->left;
		}
		else if (p->data < n && p->right != NULL)     //갈 수 있는 오른쪽 끝으로
		{
			nowlevel++;
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

void BST_input(int n)
{
	//BST에 랜덤한 정수를 삽입
	start1 = clock();
	for (int i = 0; i < n; i++)
	{
		root = insert(root, rand()*rand());
	}
	end1 = clock();
	printf("%d번 입력하는 시간 = %.8f\n", n, (float)(end1 - start1) / CLOCKS_PER_SEC);
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
	if (node != NULL)                             //있나 없나 체크
	{
		printf("발견\n");
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
	printf("탐색에 걸리는 시간의 평균 : %.8f\n", timeAvarge / 100000);
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
