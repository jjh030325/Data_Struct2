/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[100000], b[100000], c[100000];

void selectionSort(int a[], int n)
{
	int m, mindex;
	for (int i = 0; i < n - 1; i++)
	{
		m = a[i];
		mindex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (m > a[j])
			{
				m = a[j];
				mindex = j;
			}
		}
		int tmp = a[i];
		a[i] = a[mindex];
		a[mindex] = tmp;
	}
}

void bubbleSort(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void insertSort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void inputarr(int a[], int b[], int c[], int n)
{
	int in;
	for (int i = 0; i < n; i++)
	{
		in = rand() % 50000 + 1;
		a[i] = in;
		b[i] = in;
		c[i] = in;
	}
}

void printarr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	
	clock_t start, end;

	for (int i = 10000; i <= 100000; i = i + 10000)
	{
		printf("%d �迭\n", i);
		inputarr(a, b, c, i);

		start = clock();
		selectionSort(a, i);
		end = clock();
		printf("���� �ȵ� �迭 selection : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
		start = clock();
		selectionSort(a, i);
		end = clock();
		printf("���ĵ� �迭 selection : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

		start = clock();
		bubbleSort(b, i);
		end = clock();
		printf("���� �ȵ� �迭 bubble : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
		start = clock();
		bubbleSort(b, i);
		end = clock();
		printf("���ĵ� �迭 bubble : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

		start = clock();
		insertSort(c, i);
		end = clock();
		printf("���� �ȵ� �迭 insert : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
		start = clock();
		insertSort(c, i);
		end = clock();
		printf("���ĵ� �迭 insert : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
	}
	
	return 0;
}
*/

/*
Selection, Bubble, Insert ���� ����� �����ϰ� �Ʒ��� ������ �����Ͻÿ�.
1. 1~50,000 ������ ������ ���� �����Ͽ� 10,000 �������� �迭�� �Է��Ͻÿ�.
2. 1���� ������ ������ �迭�� �� ���� ������� ������ �����Ͻÿ�.
3. 2���� ������ �ð��� �����Ͻÿ�.
4. 2���� ������ �迭�� �ٽ� �����ϰ� �̿� ���� �ð��� ������ ���ÿ�. (adaptability Ư�� �ľ�)
5. 1���� �迭�� ����� 10,000�� �����Ͽ� 100,000�� ���� �����Ͽ� ���� ������ ������ ���ÿ�.
*/