/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Word
{
	char english[50];
	char korean[50];
}Word;

typedef struct Hash
{
	int bucket;
	int slot;
	Word** array;
}Hash;

Hash* CreateHashTable(int bucket, int slot)
{
	Hash* h = (Hash*)malloc(sizeof(Hash));
	h->bucket = bucket;
	h->slot = slot;
	h->array = (Word**)malloc(sizeof(Word*)*bucket);
	for (int i = 0; i < bucket; i++)
		h->array[i] = (Word*)malloc(sizeof(Word) * slot);

	return h;
}

void Search(Hash *H, const char* key)
{
	int findcheck = 0;
	int add = int(key) % H->bucket;
	printf("Search %s\n", key);
	for (int j = 0; j < H->bucket; j++)
	{
		for (int i = 0; i < H->slot; i++)
		{
			if (H->array[add][i].english == key)
			{
				printf("%s을 찾아냈습니다.\n", key);
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
		printf("찾지 못했습니다\n");
	}
}

void Insert(Hash *H, const char* key, const char* key2)
{
	int overcheck = 0;
	int add = int(key) % H->bucket;

	for (int j = 0; j < H->bucket; j++)
	{
		for (int i = 0; i < H->slot; i++)
		{
			if (H->array[add][i].english == key)
			{
				printf("이미 존재함\n");
				overcheck = 1;
				break;
			}
			if (H->array[add][i].english == NULL)
			{
				strcpy(H->array[add][i].english, key);
				strcpy(H->array[add][i].korean, key2);
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

Hash* Delete(Hash *H, const char* key)
{
	int findcheck = 0;
	int add = int(key) % H->bucket;
	while (1)
	{
		for (int i = 0; i < H->slot; i++)
		{
			if (H->array[add][i].english == key)
			{
				strcpy(H->array[add][i].english, NULL);
				strcpy(H->array[add][i].korean, NULL);
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
	return H;
}

void print(Hash *H)
{
	for (int i = 0; i < H->bucket; i++)
	{
		for (int j = 0; j < H->slot; j++)
		{
			if (H->array[i][j].english != NULL)
			{
				printf("%s %s", H->array[i][j].english, H->array[i][j].korean);
			}
		}
		printf("\n");
	}
}


int main()
{
	Hash *h;
	char in[50], in2[50];
	char input;

	h = CreateHashTable(7, 2);

	Insert(h, "apple", "사과");
	Insert(h, "banana", "바나나");
	Insert(h, "candy", "사탕");
	Insert(h, "department", "백화점");
	Insert(h, "error", "오류");
	Insert(h, "fire", "불");
	Insert(h, "bus", "버스");
	Insert(h, "birthday", "생일");
	Insert(h, "cloth", "옷");

	while (1)
	{
		scanf("%c", &input);
		switch (input)
		{
		case 'i':
			scanf("%s", in); //영어
			scanf("%s", in2); //한글
			Insert(h, in, in2);
			break;
		case 's':
			scanf("%s", in); //영어
			Search(h, in);
			break;
		case 'd':
			scanf("%s", in); //영어
			Delete(h, in);
			break;
		case 'p':
			print(h);
			break;
		case 'x':
			return 0;
		}
	}

	return 0;
}
*/