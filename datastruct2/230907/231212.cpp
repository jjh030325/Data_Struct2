#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int left, int right) {
	int pivot = A[left];
	int i = left + 1;

	for (int j = left + 1; j <= right; j++) {
		if (A[j] < pivot) {
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
		}
	}

	int tmp = A[i - 1];
	A[i - 1] = A[left];
	A[left] = tmp;
	return i - 1;
}

int partitionMedian(int A[], int left, int right) {
	int tmp;
	int mid = (left + right) / 2;
	if (A[left] > A[mid])
	{
		tmp = A[left];
		A[left] = A[mid];
		A[mid] = tmp;
	}
	if (A[left] > A[right])
	{
		tmp = A[left];
		A[left] = A[right];
		A[right] = tmp;
	}
	if (A[mid] > A[right])
	{
		tmp = A[mid];
		A[mid] = A[right];
		A[right] = tmp;
	}
	tmp = A[mid];
	A[mid] = A[left];
	A[left] = tmp;
	return partition(A, left, right);
}

void QuickSort(int A[], int left, int right) {
	if (left < right) {
		int p = partition(A, left, right);
		QuickSort(A, left, p - 1);
		QuickSort(A, p + 1, right);
	}
}

void QuickSortMedian(int A[], int left, int right) {
	if (left < right) {
		int p = partitionMedian(A, left, right);
		QuickSortMedian(A, left, p - 1);
		QuickSortMedian(A, p + 1, right);
	}
}

void unSortedArrMake(int A[], int B[], int C[], int n) {
	for (int i = 0; i < n; i++) {
		int index = rand() % 50000 + 1;
		A[i] = index;
		B[i] = index;
		C[i] = index;
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

void hybridSort(int A[], int left, int right, int threshold) {
	if (left < right) {
		if (right - left + 1 <= threshold) {
			insertSort(A + left, right - left + 1);
		}
		else {
			int p = partition(A, left, right);
			hybridSort(A, left, p - 1, threshold);
			hybridSort(A, p + 1, right, threshold);
		}
	}
}
int arr[100000], arr2[100000], arr3[100000];
int main() {
	srand((unsigned int)time(NULL));
	clock_t start, end;

	unSortedArrMake(arr, arr2, arr3, 100000);

	start = clock();
	QuickSort(arr, 0, 99999);
	end = clock();
	printf("왼쪽을 피봇으로 한 QuickSort 시간 : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	QuickSortMedian(arr2, 0, 99999);
	end = clock();
	printf("중간값을 피봇으로 한 QuickSort 시간 : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	hybridSort(arr3, 0, 99999, 10);
	end = clock();
	printf("삽입정렬과 함께 사용한 QuickSort 시간 : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}


/*
A. Quick 정렬 방식을 아래와 같이 구하시오.
1. 1~50,000 사이의 랜덤한 값을 생성하여 10,000 사이즈의 배열에 입력하시오.
2. 1에서 생성한 비정렬 배열을 두가지 Quick 정렬 방식으로 정렬하시오.
2-1. pivot을 배열의 가자 왼쪽 값으로 선택하시오.
2-2. pivot을 median 값으로 선택하시오.
3. 2에서 수행한 시간을 측정하시오.

B. Quick, Insertion 정렬을 활용하여 최고의 성능을 가지도록 배열의 크기를 설정하시오.
1. 1~50,000 사이의 랜덤한 값을 생성하여 10,000 사이즈의 배열에 입력하시오.
2. Quick 정렬만 사용했을 때와 연산시간과 Quick, Insertion 정렬을 조합하여 사용한 정렬 방식의 연산시간을 비교하시오.
3. 최적의 정렬시간을 가지도록 Insertion 정렬이 수행될 때의 배열의 크기를 조정하시오.
*/