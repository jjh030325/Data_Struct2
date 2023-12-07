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
		printf("%d 배열\n", i);
		inputarr(a, b, c, i);

		start = clock();
		selectionSort(a, i);
		end = clock();
		printf("정렬 안된 배열 selection : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
		start = clock();
		selectionSort(a, i);
		end = clock();
		printf("정렬된 배열 selection : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

		start = clock();
		bubbleSort(b, i);
		end = clock();
		printf("정렬 안된 배열 bubble : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
		start = clock();
		bubbleSort(b, i);
		end = clock();
		printf("정렬된 배열 bubble : %f\n", (float)(end - start) / CLOCKS_PER_SEC);

		start = clock();
		insertSort(c, i);
		end = clock();
		printf("정렬 안된 배열 insert : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
		start = clock();
		insertSort(c, i);
		end = clock();
		printf("정렬된 배열 insert : %f\n", (float)(end - start) / CLOCKS_PER_SEC);
	}
	
	return 0;
}
*/

/*
Selection, Bubble, Insert 정렬 방식을 구현하고 아래의 과정을 수행하시오.
1. 1~50,000 사이의 랜덤한 값을 생성하여 10,000 사이즈의 배열에 입력하시오.
2. 1에서 생성한 비정렬 배열을 각 각의 방식으로 정렬을 수행하시오.
3. 2에서 수행한 시간을 측정하시오.
4. 2에서 정렬한 배열을 다시 정렬하고 이에 대한 시간을 측정해 보시오. (adaptability 특성 파악)
5. 1에서 배열의 사이즈를 10,000씩 증가하여 100,000개 까지 변경하여 위의 과정을 측정해 보시오.
*/