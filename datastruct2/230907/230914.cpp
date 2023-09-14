#define _CRT_SECURE_NO_WARNiNGS_
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
} TreeNode;

typedef struct stackNode {
	struct TreeNode* data;
	struct stackNode* link;
} stackNode;

void push(stackNode** top, TreeNode* item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));    //����� �ȳѾ�ٸ� ��� �߰�
	if (!temp)
		exit(1);
	temp->data = item;
	temp->link = *top;
	*top = temp;
	//printf("%c", temp->data);                                  //�Է��� �ߴٴ� ���� ǥ���ϱ� ���� printf
}
stackNode* createStack()                                        //���� ����
{
	stackNode* p = NULL;
	return p;
}

TreeNode* pop(stackNode** top)                                    //���� ���� ���� �����ϸ鼭 ����ϴ� �Լ�
{
	stackNode* p = *top;
	if (p == NULL)                                              //������ �� ���
		exit(1);
	*top = p->link;                                             //top�� ������ �ι�°�� �Ű���
	TreeNode *data = p->data;                                     //������ ���� ������
	free(p);                                                    //���� �� ���� ù ��� ����
	return data;
}
void deleteStack(stackNode** top)                               //���� ���� �Լ�
{
	stackNode* p = *top;                                        //�����Ͱ� �ϳ���� �Űܴٴϸ鼭 ������ �Ұ���
	stackNode* pp;                                              //������ ���� ������ ���� �ϳ� �߰�
	while (p != NULL)
	{
		pp = p;                                                 //������ ��ġ �ּ� ����
		p = p->link;                                            //����ĭ �̵�
		free(pp);                                               //����
	}
	*top = NULL;
}
bool Empty_Stack(stackNode** p)
{
	return *p == NULL;
}

TreeNode* CreateNode(int data)                                 //������� ���� Ʈ����带 ����� �Լ�
{
	TreeNode* newNode = (TreeNode *)malloc(sizeof(TreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void MakeBinaryTree(TreeNode* parent, TreeNode* lson, TreeNode* rson)   //Ʈ������� ������ �̾��ִ� �Լ�
{
	parent->left = lson;
	parent->right = rson;
}

void preorder(TreeNode* now)                                            //��͸� Ȱ���� ������ȸ
{
	if (now->data != NULL)
	{
		printf("%c ", now->data);
	}
	if (now->left != NULL)
	{
		preorder(now->left);
	}
	if (now->right != NULL)
	{
		preorder(now->right);
	}
}


int main()
{
	TreeNode *a, *b, *c, *d, *e, *f;             //Ʈ����� ����
	a = CreateNode('a');                         //Ʈ����忡 ���� �־���
	b = CreateNode('b');
	c = CreateNode('c');
	d = CreateNode('d');
	e = CreateNode('e');
	f = CreateNode('f');

	MakeBinaryTree(a, b, c);                     //Ʈ����带 ������
	MakeBinaryTree(b, d, e);
	MakeBinaryTree(c, f, NULL);                  //����ִ� ������ NULL�� ó��

	preorder(a);                                 //������ȸ�� ���

	free(a); free(b); free(c); free(d), free(e), free(f);    //�޸� �Ҵ��� ��������.
	return 0;
}