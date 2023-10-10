/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[1001] = { false, };       //1에서 1000 사이 중복 체크용 배열
int case_check = 0;

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
			case_check = 3;
		}
		else { //자식이 하나 또는 없는 경우
			temp = root;
			if (root->left == NULL)            //하나의 서브트리 있는 경우
			{
				root = root->right;
				if (root != NULL)              //리프노드인 경우
				{
					case_check = 1;
				}
				else
				{
					case_check = 2;
				}
			}	
			else if (root->right == NULL)      //왼쪽이 있는데 오른쪽이 없음
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
			input = rand() % 1000 + 1;            //1에서 1000사이
			if (data_check[input] == false)      //나온 적 없는 경우
			{
				data_check[input] = true;        //나왔다고 체크 후 빠져나옴
				break;
			}
		}
		root = insert(root, input);              //노드삽입
	}
	return root;
}

int chooseNode()
{
	int input;
	while (1)
	{
		input = rand() % 1000 + 1;            //1에서 100사이
		if (data_check[input] == true)
		{
			return input;
		}
	}
	
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


int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //트리노드 선언
	int choose;

	root = randomTree_BST(root, 10);

	levelOrder(root);
	choose = chooseNode();                         //노드 선택
	root = deleteBSTN(root, choose);
	printf("\n");
	levelOrder(root);
	printf("case %d", case_check);

	return 0;
}
*/