#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[101] = { false, };       //1에서 100 사이 중복 체크용 배열

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

// 큐 구현을 위한 구조체 정의
struct QueueNode {
	struct BinarySearchTreeNode* data;
	struct QueueNode* next;
};

// 큐 구조체 정의
struct Queue {
	struct QueueNode* front;
	struct QueueNode* rear;
};

// 큐 초기화
struct Queue* createQueue() {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

// 큐에 요소 추가
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

// 큐에서 요소 제거
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

// 레벨 순회 함수
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
		if (p->data > n && p->left != NULL)           //갈 수 있는 왼쪽 끝으로
		{
			p = p->left;
		}
		else if (p->data < n && p->right != NULL)     //갈 수 있는 오른쪽 끝으로
		{
			p = p->right;
		}
		else if(p->data == n)                         //이미 있는 경우 리턴
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

// 반복적인 탐색 함수
BinarySearchTreeNode *search(BinarySearchTreeNode *node, int key)
{
	while (node != NULL) {
		if (key == node->data) return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; // 탐색에 실패했을 경우 NULL 반환
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
			input = rand() % 100 + 1;            //1에서 100사이
			if (data_check[input] == false)      //나온 적 없는 경우
			{
				data_check[input] = true;        //나왔다고 체크 후 빠져나옴
				break;
			}
		}
		printf("%d번째 숫자 = %d\n", i, input);  //출력
		root = insert(root, input);              //노드삽입
	}
	return root;
}

int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //트리노드 선언
	int n;

	scanf("%d", &n);

	root = randomTree_BST(root, n);

	inorder(root);
	printf("\n");
	levelOrder(root);

	return 0;
}

/*
1. BST의 insert 함수 생성
BST의 입력함수를 생성하고, level order, inorder 방식으로 출력하시오.
입력 데이터 {18, 7, 26, 3, 12, 31, 27}

2. 랜덤한 BST 만들기
1~100 사이의 임의의 숫자를 선택하여 BST를 만드시오.
(단, 중복된 값은 선택되지 않게하고, 노드의 갯수는 함수의 파라미터로 받게 하시오.)
예) 7개의 값을 선택해 BST를 만드는 함수: root_BST = randomTree_BST(7);
*/