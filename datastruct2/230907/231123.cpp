/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Hash
{
	int bucket;
	int slot;
	int** array;
}Hash;

Hash* CreateHashTable(int bucket, int slot)
{
	Hash* h = (Hash*)malloc(sizeof(Hash));
	h->bucket = bucket;
	h->slot = slot;
	h->array = (int**)malloc(sizeof(int*)*bucket);
	for (int i = 0; i < bucket; i++)
		h->array[i] = (int*)malloc(sizeof(int) * slot);
	for (int i = 0; i < bucket; i++)
		for (int j = 0; j < slot; j++)
			h->array[i][j] = 0;
	return h;
}
void Search(Hash *H, int key)
{
	int findcheck = 0;
	int add = key % H->bucket;
	for (int i = 0; i < H->slot; i++)
	{
		if (H->array[add][i] == key)
		{
			printf("find %d\n", key);
			findcheck = 1;
			break;
		}
	}
	if (findcheck == 0)
	{
		printf("Fail..\n");
	}
}

void Insert(Hash *H, int key)
{
	int overcheck = 0;
	int add = key % H->bucket;
	for (int i = 0; i < H->slot; i++)
	{
		if (H->array[add][i] == 0)
		{
			H->array[add][i] = key;
			overcheck = 1;
			break;
		}
	}
	if (overcheck == 0)
	{
		printf("overflow\n");
	}
}

void Delete(Hash *H, int key)
{
	int findcheck = 0;
	int add = key % H->bucket;
	for (int i = 0; i < H->slot; i++)
	{
		if (H->array[add][i] == key)
		{
			H->array[add][i] = 0;
			findcheck = 1;
			break;
		}
	}
	if (findcheck == 0)
	{
		printf("Fail...\n");
	}
}

void print(Hash *H)
{
	for (int i = 0; i < H->bucket; i++)
	{
		for (int j = 0; j < H->slot; j++)
		{
			printf("%d ", H->array[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	Hash *h;
	char choose;
	int bucket, slot, input;
	printf("Input a number of the bucket and the slot: ");
	scanf("%d %d", &bucket, &slot);
	h = CreateHashTable(bucket, slot);

	while (1)
	{
		printf("Input a menu (i, s, d, p, x): ");
		scanf(" %c", &choose);
		switch (choose)
		{
		case 'i':
			//입력
			scanf("%d", &input);
			Insert(h, input);
			break;
		case 's':
			//검색
			scanf("%d", &input);
			Search(h, input);
			break;
		case 'd':
			//삭제
			scanf("%d", &input);
			Delete(h, input);
			break;
		case 'p':
			//출력
			print(h);
			break;
		case 'x':
			//종료
			return 0;
		}
	}

	return 0;
}
*/