/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Graph {
	int V;
	int E;
	int** Adj; //이차원 행렬을 위해
} Graph;

Graph* AdjMatrix(int v, int e) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	if (!G) {
		printf("Memory Error");
		return 0;
	}
	G->V = v;
	G->E = e;
	G->Adj = (int**)malloc(sizeof(int*) * G->V);
	for (int i = 0; i < G->V; i++)
		G->Adj[i] = (int*)malloc(sizeof(int) * G->V);
	for (int i = 0; i < G->V; i++)
		for (int j = 0; j < G->V; j++)
			G->Adj[i][j] = 0;
	return G;
}

Graph* insert_direct(Graph* G)
{
	int u, v;
	for (int i = 0; i < G->E; i++)
	{
		u = rand() % G->V;
		v = rand() % G->V;
		
		if (u >= G->V || v >= G->V) {
			i--;
		}
		else if(G->Adj[u][v] == 1)
		{
			printf("연결 = %d, %d는 중복이라 삭제\n", u, v);
			i--;
		}
		else
		{
			printf("%d번째 연결 = %d, %d\n", i, u, v);
		}
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

void deleteMatrix(Graph* G) {
	for (int i = 0; i < G->V; i++)	
		free(G->Adj[i]);
	free(G->Adj);
	free(G);
}
void print_adj_mat(Graph* G) {
	if (G->Adj == NULL) {
		printf("No Matrix exist!\n");
		return;
	}
	printf("\n Adjacency Matrix of Direct Graph\n");
	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			printf("%2d ", G->Adj[u][v]);
		}
		printf("\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int v, e;

	v = rand() % 6 + 5;
	e = rand() % 6 + 5;

	Graph *g = AdjMatrix(v, e);

	printf("v = %d e = %d\n", v, e);

	g = insert_direct(g);           //입력
	print_adj_mat(g);               //출력
	deleteMatrix(g);                //삭제

	return 0;
}
*/