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
	for (int size = 1; size < n; size *= 2) {                                               //배열의 사이즈 한칸부터 시작해서 두배로 늘려나감.
		for (int start = 0; start < n - 1; start += 2 * size) {                             //0부터 사이즈만큼씩 분리해서 계산해나감.
			int mid = start + size - 1;                                                     //중간값 계산
			int end;
			if ((start + 2 * size - 1) < (n - 1)) {                                         //범위를 벗어나지 않는 경우
				end = (start + 2 * size - 1);                                               //계산된 것 두개의 위치만큼 계산해서 마지막위치 계산.
			}
			else {
				end = (n - 1);                                                              //범위를 벗어나는 경우 배열의 마지막으로 마지막 위치
			} 
			merge(A, start, mid, end);                                                      //합쳐줌.
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