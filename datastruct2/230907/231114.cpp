/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VERTICES 10

int Visited[MAX_VERTICES];

typedef struct Graph {
	int V;     //노드개수
	int E;     //연결 선 개수
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

Graph* insert(Graph* G, int u, int v)
{
	G->Adj[u][v] = 1;
	G->Adj[v][u] = 1;
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

void DFS(Graph* G, int u) {
	Visited[u] = 1;
	
	for (int v = 0; v < G->V; v++) {
		if (!Visited[v] && G->Adj[u][v])
		{
			printf("%d %d\n", u, v);
			//방문하지 않았고, 갈 수 있는 경우
			DFS(G, v);
		}
	}
}int main(){
	Graph *mygraph = AdjMatrix(8, 7);

	insert(mygraph, 0, 1);
	insert(mygraph, 1, 2);
	insert(mygraph, 2, 3);
	insert(mygraph, 4, 5);
	insert(mygraph, 4, 6);
	insert(mygraph, 4, 7);
	insert(mygraph, 1, 4);

	print_adj_mat(mygraph);

	printf("\nDFS 깊이우선 탐색 결과\n");
	for (int i = 0; i < mygraph->V; i++)
	{
		DFS(mygraph, i);
	}
	
	deleteMatrix(mygraph);                //삭제
	return 0;}*/