/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool data_check[1001] = { false, };       //1���� 1000 ���� �ߺ� üũ�� �迭
int case_check = 0;

struct BinarySearchTreeNode {
	int data;
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
			case_check = 3;
		}
		else { //�ڽ��� �ϳ� �Ǵ� ���� ���
			temp = root;
			if (root->left == NULL)            //�ϳ��� ����Ʈ�� �ִ� ���
			{
				root = root->right;
				if (root != NULL)              //��������� ���
				{
					case_check = 1;
				}
				else
				{
					case_check = 2;
				}
			}	
			else if (root->right == NULL)      //������ �ִµ� �������� ����
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
			input = rand() % 1000 + 1;            //1���� 1000����
			if (data_check[input] == false)      //���� �� ���� ���
			{
				data_check[input] = true;        //���Դٰ� üũ �� ��������
				break;
			}
		}
		root = insert(root, input);              //������
	}
	return root;
}

int chooseNode()
{
	int input;
	while (1)
	{
		input = rand() % 1000 + 1;            //1���� 100����
		if (data_check[input] == true)
		{
			return input;
		}
	}
	
}

int main()
{
	srand(time(NULL));
	BinarySearchTreeNode *root = NULL;             //Ʈ����� ����
	int choose;

	root = randomTree_BST(root, 10);

	inorder(root);
	choose = chooseNode();                         //��� ����
	root = deleteBSTN(root, choose);
	printf("\n");
	inorder(root);
	printf("case %d", case_check);

	return 0;
}
*/