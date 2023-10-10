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
	//data�� ��ġ �˻�
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (f->makeday < root->input->makeday)
		root->left = deleteBSTN(root->left, f);
	else if (f->makeday > root->input->makeday)
		root->right = deleteBSTN(root->right, f);	//data�� ã�� ���
	else {
		//�ڽ��� 2���� ��� ������ ����Ʈ���� �ּڰ��� ��ü�Ѵ�. (������ �ݴ��)
		if (root->left && root->right) {
			temp = FindMin(root->right);
			root->input = temp->input;
			root->right = deleteBSTN(root->right, root->input);
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
		if (p->input->makeday > f->makeday && p->left != NULL)           //�� �� �ִ� ���� ������
		{
			p = p->left;
		}
		else if (p->input->makeday < f->makeday && p->right != NULL)     //�� �� �ִ� ������ ������
		{
			p = p->right;
		}
		else if (p->input->makeday == f->makeday)                         //�̹� �ִ� ��� ����
		{
			return node;
		}
		else
		{
			if (p->input->makeday > f->makeday)                          //���̻� �� ���� ���� ��� ��� �߰��� �̾���
			{
				p->left = newNode;
				return node;
			}
			else if (p->input->makeday < f->makeday)                     //���̻� �� ���� ���� ��� ��� �߰��� �̾���
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
		int cmp = strcmp(p->input->name, f->name); // �̸� ��
		if (cmp > 0 && p->left != NULL)           // �� �� �ִ� ���� ������
		{
			p = p->left;
		}
		else if (cmp < 0 && p->right != NULL)     // �� �� �ִ� ������ ������
		{
			p = p->right;
		}
		else if (cmp == 0)                         // �̹� �ִ� ��� ����
		{
			return node;
		}
		else
		{
			if (cmp > 0)                          // ���̻� �� ���� ���� ��� ��� �߰��� �̾���
			{
				p->left = newNode;
				return node;
			}
			else if (cmp < 0)                     // ���̻� �� ���� ���� ��� ��� �߰��� �̾���
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
			printf("����\n");
			return;
		}
		else if (f->makeday < node->input->makeday)
			node = node->left;
		else
			node = node->right;
	}
	printf("����\n");
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
		printf("i = �Է�, d = ����, e = �˻�, p = ���, q = ����***: \n");
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
			printf("�켱���� : ����\n");
			inorder(root_num);
			printf("\n�켱���� : �̸�\n");
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