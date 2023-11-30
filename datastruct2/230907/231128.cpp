/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int count = 0;
	printf("Search %d\n", key);
	for (int j = 0; j < H->bucket; j++)
	{
		for (int i = 0; i < H->slot; i++)
		{
			count++;
			if (H->array[add][i] == key)
			{
				printf("%d번 탐색해서 %d을 찾아냈습니다.\n", count, key);
				findcheck = 1;
				break;
			}
		}
		if (findcheck == 0 && add < H->bucket - 1)
		{
			add++;
		}
		else if (findcheck == 0)
		{
			add = 0;
		}
		else if (findcheck == 1)
		{
			break;
		}
	}
	if (findcheck == 0)
	{
		printf("%d번 탐색했지만, 결국 찾지 못했습니다..\n", count);
	}
}

void Insert(Hash *H, int key)
{
	int overcheck = 0;
	int add = key % H->bucket;
	for (int j = 0; j < H->bucket; j++)
	{
		for (int i = 0; i < H->slot; i++)
		{
			if (H->array[add][i] == key)
			{
				printf("이미 존재함\n");
				overcheck = 1;
				break;
			}
			if (H->array[add][i] == 0)
			{
				H->array[add][i] = key;
				overcheck = 1;
				break;
			}
		}
		if (overcheck == 0 && add < H->bucket - 1)
		{
			add++;
		}
		else if (overcheck == 0)
		{
			add = 0;
		}
		else if (overcheck == 1)
		{
			break;
		}
	}
	if (overcheck == 0)
	{
		printf("over\n");
	}
}

void Delete(Hash *H, int key)
{
	int findcheck = 0;
	int add = key % H->bucket;
	while (1)
	{
		for (int i = 0; i < H->slot; i++)
		{
			if (H->array[add][i] == key)
			{
				H->array[add][i] = 0;
				findcheck = 1;
				break;
			}
		}
		if (findcheck == 0 && add < H->bucket - 1)
		{
			add++;
		}
		else
		{
			printf("없어요..\n");
			break;
		}
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
	srand((unsigned int)time(NULL));
	bool check[31] = { false, };
	Hash *h;
	int input;

	h = CreateHashTable(10, 2);

	for (int i = 0; i < 21; i++)
	{
		input = rand() % 30 + 1;
		if (check[input] == false)
		{
			Insert(h, input);
			check[input] = true;
		}
		else
		{
			i--;
		}
	}

	//검색
	input = rand() % 30 + 1;
	Search(h, input);

	//출력
	print(h);

	return 0;
}
*/