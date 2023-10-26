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

void sort_arr(int n)
{
	//정렬된 배열 만들어주기
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
	//data의 위치 검색
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (data < root->data)
		root->left = deleteBSTN(root->left, data);
	else if (data > root->data)
		root->right = deleteBSTN(root->right, data);	//data를 찾은 경우
	else {
		//자식이 2개인 경우 오른쪽 서브트리의 최솟값과 교체한다. (기존과 반대로)
		if (root->left && root->right) {
			temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deleteBSTN(root->right, root->data);
		}
		else { //자식이 하나 또는 없는 경우
			temp = root;
			if (root->left == NULL)            //하나의 서브트리 있는 경우
			{
				root = root->right;
			}
			else if (root->right == NULL)      //왼쪽이 있는데 오른쪽이 없음
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
		printf("정리 안된 배열 최소값 : %d\n", min_arr(1000));
		del_arr(min_arr(1000));
		printf("정리된 배열 최소값 : %d\n", sortedArr[0]);
		del_sortedArr();
		printf("BST 최소값 : %d\n", FindMin(root)->data);
		root = deleteBSTN(root, FindMin(root)->data);
	}

	return 0;
}
*/

/*
우선순위 큐 구현방법 작은 값을 찾는 것.
1. 순서없는 배열
2. 정렬된 배열
3. BST

값 1-10000사이의 랜덤값 1000개 생성
*/