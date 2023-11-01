#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[7];
int count = 0;
bool successCheck = false;

//7�ڸ� ��������Ʈ�� ���� �Լ�
void makeTreeArr()
{
	for (int i = 0; i < 7; i++)
	{
		arr[i] = rand() % 100;
	}
}

//������ Ȯ���ϴ� �Լ�
bool isHeap(int n = 7) {
	// ������ ����� �θ�
	int parent = (n - 2) / 2;

	for (int i = 0; i <= parent; i++) {
		// ���� �ڽ� ���
		int leftChild = 2 * i + 1;
		// ������ �ڽ� ���
		int rightChild = 2 * i + 2;

		// ���� �ڽ� ��尡 �θ� ��庸�� ũ�� �� �ƴ�
		if (leftChild < n && arr[i] < arr[leftChild])
			return false;

		// ������ �ڽ� ��尡 �θ� ��庸�� ũ�� �� �ƴ�
		if (rightChild < n && arr[i] < arr[rightChild])
			return false;
	}
	return true;
}
//��ü �迭 ����ϴ� �Լ�
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