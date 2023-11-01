#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[7];
int count = 0;
bool successCheck = false;

//7자리 완전이진트리 생성 함수
void makeTreeArr()
{
	for (int i = 0; i < 7; i++)
	{
		arr[i] = rand() % 100;
	}
}

//힙인지 확인하는 함수
bool isHeap(int n = 7) {
	// 마지막 노드의 부모
	int parent = (n - 2) / 2;

	for (int i = 0; i <= parent; i++) {
		// 왼쪽 자식 노드
		int leftChild = 2 * i + 1;
		// 오른쪽 자식 노드
		int rightChild = 2 * i + 2;

		// 왼쪽 자식 노드가 부모 노드보다 크면 힙 아님
		if (leftChild < n && arr[i] < arr[leftChild])
			return false;

		// 오른쪽 자식 노드가 부모 노드보다 크면 힙 아님
		if (rightChild < n && arr[i] < arr[rightChild])
			return false;
	}
	return true;
}
//전체 배열 출력하는 함수
void printArr()
{
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	srand((unsigned int)time(NULL));

	while(successCheck == false)
	{
		makeTreeArr();
		count++;
		if (isHeap(7))
		{
			successCheck = true;
		}
	}
	printf("%d\n", count);
	printArr();

	return 0;
}