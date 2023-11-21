#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};

int unsortedarr[1000];
int sortedarr[1000];
bool check[2000] = { false, };

void randarr()
{
	int a;
	for (int i = 0; i < 1000; i++)
	{
		while (1)
		{
			a = rand() % 2000;
			if (a % 2 == 1)	        //홀수만
			{
				if (check[a] == false)
				{
					check[a] = true;
					break;
				}
			}
		}
		unsortedarr[i] = a;
		sortedarr[i] = a;
	}
}

void sortarr()     //오름차순 정렬
{
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sortedarr[i] < sortedarr[j])
			{
				int tmp = sortedarr[i];
				sortedarr[i] = sortedarr[j];
				sortedarr[j] = tmp;
			}
		}
	}
}

int search_bst(BinarySearchTreeNode *node, int key)
{
	int num = 0;
	while (node != NULL) {
		if (key == node->data) break;
		else if (key < node->data)
		{
			num++;
			node = node->left;
		}
		else
		{
			num++;
			node = node->right;
		}
	}
	return num;
}

int main()
{
	srand((unsigned int)time(NULL));
	int num;
	int san = 0, usan = 0, bstn = 0;
	randarr();
	sortarr();
	for (int t = 0; t < 1000; t++)
	{
		num = 0;

		int r = rand() % 2000;
		while (1)
		{
			if (r % 2 == 0)
			{
				r = rand() % 2000;
			}
			else
			{
				break;
			}
		}
		//정리안된 배열
		for (int i = 0; i < 1000; i++)
		{
			num++;
			if (unsortedarr[i] == r)
			{
				break;
			}
		}
		usan += num;
		num = 0;
		//정리된 배열
		for (int i = 0; i < 1000; i++)
		{
			num++;
			if (sortedarr[i] >= r)
			{
				break;
			}
		}
		san += num;
		num = 0;
		
		int middle = 500;
		int low = 0;
		int high = 999;

		while (1)
		{
			num++;

			if (sortedarr[middle] == r)
			{
				break;
			}
			else if (sortedarr[middle] < r)
			{
				low = middle + 1;
			}
			else // sortedarr[middle] > r
			{
				high = middle - 1;
			}

			if (low > high)
			{
				break;
			}

			middle = (low + high) / 2;
		}

		bstn += num;

	}
	
	printf("정렬안된 배열 탐색 : %d\n", usan / 1000);
	printf("정렬된 배열 탐색 : %d\n", san / 1000);
	printf("이진 탐색 : %d\n", bstn / 1000);

	return 0;
}