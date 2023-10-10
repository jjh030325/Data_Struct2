/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct file
{
	char name[20];
	int makeday;
};

struct BinarySearchTreeNode {
	struct file *input;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

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

BinarySearchTreeNode* deleteBSTN(BinarySearchTreeNode* root, file* f)
{
	BinarySearchTreeNode* temp;
	//data의 위치 검색
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (f->makeday < root->input->makeday)
		root->left = deleteBSTN(root->left, f);
	else if (f->makeday > root->input->makeday)
		root->right = deleteBSTN(root->right, f);	//data를 찾은 경우
	else {
		//자식이 2개인 경우 오른쪽 서브트리의 최솟값과 교체한다. (기존과 반대로)
		if (root->left && root->right) {
			temp = FindMin(root->right);
			root->input = temp->input;
			root->right = deleteBSTN(root->right, root->input);
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

BinarySearchTreeNode* insert_day(BinarySearchTreeNode *node, file *f)
{
	BinarySearchTreeNode* newNode = (BinarySearchTreeNode *)malloc(sizeof(BinarySearchTreeNode));
	newNode->input = f;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->input = f;
	BinarySearchTreeNode *p = node;
	if (node == NULL)
	{
		return newNode;
	}

	while (1)
	{
		if (p->input->makeday > f->makeday && p->left != NULL)           //갈 수 있는 왼쪽 끝으로
		{
			p = p->left;
		}
		else if (p->input->makeday < f->makeday && p->right != NULL)     //갈 수 있는 오른쪽 끝으로
		{
			p = p->right;
		}
		else if (p->input->makeday == f->makeday)                         //이미 있는 경우 리턴
		{
			return node;
		}
		else
		{
			if (p->input->makeday > f->makeday)                          //더이상 갈 곳이 없는 경우 노드 추가로 이어줌
			{
				p->left = newNode;
				return node;
			}
			else if (p->input->makeday < f->makeday)                     //더이상 갈 곳이 없는 경우 노드 추가로 이어줌
			{
				p->right = newNode;
				return node;
			}
		}
	}
}

BinarySearchTreeNode* insert_name(BinarySearchTreeNode *node, file *f)
{
	BinarySearchTreeNode* newNode = (BinarySearchTreeNode *)malloc(sizeof(BinarySearchTreeNode));
	newNode->input = f;
	newNode->left = NULL;
	newNode->right = NULL;
	BinarySearchTreeNode *p = node;
	if (node == NULL)
	{
		return newNode;
	}

	while (1)
	{
		int cmp = strcmp(p->input->name, f->name); // 이름 비교
		if (cmp > 0 && p->left != NULL)           // 갈 수 있는 왼쪽 끝으로
		{
			p = p->left;
		}
		else if (cmp < 0 && p->right != NULL)     // 갈 수 있는 오른쪽 끝으로
		{
			p = p->right;
		}
		else if (cmp == 0)                         // 이미 있는 경우 리턴
		{
			return node;
		}
		else
		{
			if (cmp > 0)                          // 더이상 갈 곳이 없는 경우 노드 추가로 이어줌
			{
				p->left = newNode;
				return node;
			}
			else if (cmp < 0)                     // 더이상 갈 곳이 없는 경우 노드 추가로 이어줌
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
		printf("%s %d\n", root->input->name, root->input->makeday);
		inorder(root->right);
	}
}

void search_file(BinarySearchTreeNode *node, file *f)
{
	while (node != NULL) {
		if (f->makeday == node->input->makeday)
		{
			printf("있음\n");
			return;
		}
		else if (f->makeday < node->input->makeday)
			node = node->left;
		else
			node = node->right;
	}
	printf("없음\n");
	return;
}

int main()
{
	BinarySearchTreeNode *root_num = NULL;
	BinarySearchTreeNode *root_name = NULL;
	file arr[100];
	char check;
	int i = 0;

	while (1)
	{
		printf("i = 입력, d = 삭제, e = 검색, p = 출력, q = 종료***: \n");
		scanf(" %c", &check);
		if (check == 'i')
		{
			scanf("%s %d", arr[i].name, &arr[i].makeday);
			root_num = insert_day(root_num, &arr[i]);
			root_name = insert_name(root_name, &arr[i]);
			i++;
		}
		else if (check == 'd')
		{
			scanf("%s %d", arr[i].name, &arr[i].makeday);
			root_num = deleteBSTN(root_num, &arr[i]);
			root_name = deleteBSTN(root_name, &arr[i]);
			i++;
		}
		else if (check == 'e')
		{
			scanf("%s %d", arr[i].name, &arr[i].makeday);
			search_file(root_num, &arr[i]);
			i++;
		}
		else if (check == 'p')
		{
			printf("우선순위 : 숫자\n");
			inorder(root_num);
			printf("\n우선순위 : 이름\n");
			inorder(root_name);
		}
		else if (check == 'q')
		{
			return 0;
		}
	}

	return 0;
}
*/