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
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));    //사이즈가 안넘어간다면 노드 추가
	if (!temp)
		exit(1);
	temp->data = item;
	temp->link = *top;
	*top = temp;
	//printf("%c", temp->data);                                  //입력을 했다는 것을 표시하기 위한 printf
}
stackNode* createStack()                                        //스택 생성
{
	stackNode* p = NULL;
	return p;
}

TreeNode* pop(stackNode** top)                                    //가장 위의 값을 삭제하면서 출력하는 함수
{
	stackNode* p = *top;
	if (p == NULL)                                              //스택이 빈 경우
		exit(1);
	*top = p->link;                                             //top을 위에서 두번째로 옮겨줌
	TreeNode *data = p->data;                                     //데이터 값을 빼내기
	free(p);                                                    //빼낸 후 가장 첫 노드 제거
	return data;
}
void deleteStack(stackNode** top)                               //스택 삭제 함수
{
	stackNode* p = *top;                                        //포인터가 하나라면 옮겨다니면서 삭제가 불가능
	stackNode* pp;                                              //삭제를 위해 포인터 변수 하나 추가
	while (p != NULL)
	{
		pp = p;                                                 //삭제할 위치 주소 복사
		p = p->link;                                            //다음칸 이동
		free(pp);                                               //삭제
	}
	*top = NULL;
}
bool Empty_Stack(stackNode** p)
{
	return *p == NULL;
}

TreeNode* CreateNode(int data)                                 //연결되지 않은 트리노드를 만드는 함수
{
	TreeNode* newNode = (TreeNode *)malloc(sizeof(TreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void MakeBinaryTree(TreeNode* parent, TreeNode* lson, TreeNode* rson)   //트리노드의 가지를 이어주는 함수
{
	parent->left = lson;
	parent->right = rson;
}

TreeNode* peek(stackNode** top)                                    //가장 위의 값을 삭제하면서 출력하는 함수
{
	stackNode* p = *top;
	if (p == NULL)                                              //스택이 빈 경우
		exit(1);
	TreeNode *data = p->data;                                     //데이터 값을 빼내기
	return data;
}

void postorder_iter(TreeNode* root) {
	if (root == NULL)
		return;

	stackNode* stack = createStack();
	TreeNode* now = root;
	TreeNode* lastVisited = NULL;

	while (!Empty_Stack(&stack) || now != NULL) {  //스택이 비거나 현 위치가 NULL이 아닌 경우 반복
		if (now != NULL) {
			push(&stack, now);
			now = now->left;               //왼쪽 끝까지감.
		}
		else {
			TreeNode* peekNode = peek(&stack);
			if (peekNode->right != NULL && lastVisited != peekNode->right) {   //만약 이미 출력했던 곳이라면 가지 않음.
				now = peekNode->right;         //오른쪽 끝까지감.
			}
			else {  
				printf("%c ", peekNode->data);     //더이상 내려갈 공간이 없으면 출력
				lastVisited = pop(&stack);         //한번 들린 곳 체크
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
	TreeNode *a, *b, *c, *d, *e, *f;             //트리노드 선언
	a = CreateNode('a');                         //트리노드에 값을 넣어줌
	b = CreateNode('b');
	c = CreateNode('c');
	d = CreateNode('d');
	e = CreateNode('e');
	f = CreateNode('f');

	MakeBinaryTree(a, b, c);                     //트리노드를 연결함
	MakeBinaryTree(b, d, e);
	MakeBinaryTree(c, f, NULL);                  //비어있는 공간은 NULL로 처리

	postorder_iter(a);                                 //전위순회로 출력
	printf("\n");
	postorder(a);

	free(a); free(b); free(c); free(d), free(e), free(f);    //메모리 할당을 해제해줌.
	return 0;
}
*/