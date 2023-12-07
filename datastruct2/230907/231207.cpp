/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[100000];

void merge(int list[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[100000];

	while (i <= mid && j <= right)
	{
		if (list[i] < list[j])
		{
			temp[k] = list[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = list[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = list[i];
		k++;
		i++;
	}

	while (j <= right)
	{
		temp[k] = list[j];
		k++;
		j++;
	}

	for (i = left; i <= right; i++)
	{
		list[i] = temp[i];
	}
}


void MergeSort(int A[], int p, int q)
{
	if (p < q) {
		int k = (p + q) / 2;
		MergeSort(A, p, k);
		MergeSort(A, k + 1, q);
		merge(A, p, (p + q) / 2, q);
	}
}

void iterMergeSort(int A[], int n) {
	for (int size = 1; size < n; size *= 2) {                                               //�迭�� ������ ��ĭ���� �����ؼ� �ι�� �÷�����.
		for (int start = 0; start < n - 1; start += 2 * size) {                             //0���� �����ŭ�� �и��ؼ� ����س���.
			int mid = start + size - 1;                                                     //�߰��� ���
			int end;
			if ((start + 2 * size - 1) < (n - 1)) {                                         //������ ����� �ʴ� ���
				end = (start + 2 * size - 1);                                               //���� �� �ΰ��� ��ġ��ŭ ����ؼ� ��������ġ ���.
			}
			else {
				end = (n - 1);                                                              //������ ����� ��� �迭�� ���������� ������ ��ġ
			} 
			merge(A, start, mid, end);                                                      //������.
		}
	}
}

int main()
{
	for (int i = 0; i < 50; i++)
	{
		a[i] = 50 - i;
	}
	for (int i = 0; i < 50; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	iterMergeSort(a, 50);

	for (int i = 0; i < 50; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	return 0;
}
*/