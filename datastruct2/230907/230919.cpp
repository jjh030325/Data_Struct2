/*
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

TreeNode* peek(stackNode** top)                                    //���� ���� ���� �����ϸ鼭 ����ϴ� �Լ�
{
	stackNode* p = *top;
	if (p == NULL)                                              //������ �� ���
		exit(1);
	TreeNode *data = p->data;                                     //������ ���� ������
	return data;
}

void postorder_iter(TreeNode* root) {
	if (root == NULL)
		return;

	stackNode* stack = createStack();
	TreeNode* now = root;
	TreeNode* lastVisited = NULL;

	while (!Empty_Stack(&stack) || now != NULL) {  //������ ��ų� �� ��ġ�� NULL�� �ƴ� ��� �ݺ�
		if (now != NULL) {
			push(&stack, now);
			now = now->left;               //���� ��������.
		}
		else {
			TreeNode* peekNode = peek(&stack);
			if (peekNode->right != NULL && lastVisited != peekNode->right) {   //���� �̹� ����ߴ� ���̶�� ���� ����.
				now = peekNode->right;         //������ ��������.
			}
			else {  
				printf("%c ", peekNode->data);     //���̻� ������ ������ ������ ���
				lastVisited = pop(&stack);         //�ѹ� �鸰 �� üũ
			}
		}
	}

	deleteStack(&stack);
}


void postorder(TreeNode *x)
{
	if (x != NULL)
	{
		postorder(x->left);
		postorder(x->right);
		printf("%c ", x->data);
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

	postorder_iter(a);                                 //������ȸ�� ���
	printf("\n");
	postorder(a);

	free(a); free(b); free(c); free(d), free(e), free(f);    //�޸� �Ҵ��� ��������.
	return 0;
}
*/