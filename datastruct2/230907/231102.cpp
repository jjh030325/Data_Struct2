/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Heap {
	int* array;
	int count; // 힙 안의 항목 개수
	int capacity; // 힙의 용량
	int heap_type; //힙의 종류
};
bool check[100];
int arr[11];

Heap* CreateHeap(int capacity, int heap_type) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	if (h == NULL) {
		printf("Memory Error");
		return 0;
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int) * h->capacity);
	if (h->array == NULL) {
		printf("Memory Error");
		return 0;
	}
	return h;
}
int Parent(Heap* h, int i) {
	if (i <= 0 || i >= h->count)
		return -1;
	return (i - 1) / 2;
}
int LeftChild(Heap* h, int i) {
	int left = 2 * i + 1;
	if (left >= h->count)
		return -1;
	return left;
}
int RightChild(Heap* h, int i) {
	int right = 2 * i + 2;
	if (right >= h->count)
		return -1;
	return right;
}
void PercolateDown(struct Heap* h, int i) {
	int l, r, max, temp;
	l = LeftChild(h, i);
	r = RightChild(h, i);
	if (l != -1 && h->array[l] > h->array[i]) max = l;
	else max = i;
	if (r != -1 && h->array[r] > h->array[max]) max = r;
	if (max != i) {
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		PercolateDown(h, max);
	}
}int DeleteMax(Heap* h)
{
	int data;
	if (h->count == 0)
		return -1;
	data = h->array[0];
	h->array[0] = h->array[h->count - 1];
	h->count--;
	PercolateDown(h, 0);
	return data;
}
void PercolateUp(Heap* h, int i) {
	int p, temp;
	if (i != 0) 
	{ // 루트 노드가 아닌 경우에만 수행
		p = Parent(h, i); // 1. insert된 노드의 부모노드 찾기
		if (h->array[p] < h->array[i]) { // 2. 부모와 insert 노드의 값 비교
			// 3. insert 노드의 값이 크면 swap
			temp = h->array[p];
			h->array[p] = h->array[i];
			h->array[i] = temp;
			PercolateUp(h, p); // 4. PercolateUp();
		}
	}
}
void InsertHeap(Heap *h, int data)
{
	if (h->count < h->capacity)
	{
		h->array[h->count] = data;
		h->count++;
		PercolateUp(h, h->count - 1);
	}
	else
	{
		printf("범위초과");
	}
}
void randomHeapdata(int n){	int data;	for (int i = 0; i < n; i++)	{		data = rand() % 100;		if (check[data] == true)		{			i--;		}		else		{			check[data] = true;			arr[i] = data;		}	}}void printHeapAll(Heap* h){	for (int i = 0; i < h->count; i++)	{		printf("%d ", h->array[i]);	}	printf("\n");}
void printarr(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void BuildHeap(Heap* h, int A[], int n) {
	for (int i = 0; i < n; i++) {
		h->array[i] = A[i];
	}
	h->count = n;
	for (int i = (n - 2) / 2; i >= 0; i--)
		PercolateDown(h, i);
}

int main()
{
	srand((unsigned int)time(NULL));
	Heap *h = NULL;
	h = CreateHeap(11, 1);
	randomHeapdata(11);

	printarr(11);

	BuildHeap(h, arr, 11);

	printHeapAll(h);

	return 0;
}
*/