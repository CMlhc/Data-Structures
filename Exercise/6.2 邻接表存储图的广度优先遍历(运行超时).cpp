#include<malloc.h>

void BFS(LGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	int *q;
	int MaxSize = 100;
	q = (int *)malloc(sizeof(int)*MaxSize);
	int Front =-1;
	int Rear = 0;

	PtrToAdjVNode W;
	int V;

	Visit(S);
	Visited[S] = true;

	q[++Rear%MaxSize] = S;
	while (Front!=Rear)
	{
		V = q[++Front%MaxSize];
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
		{
			if (!Visited[W->AdjV])
			{
				Visit(W->AdjV);
				Visited[W->AdjV] = true;
				q[++Rear%MaxSize]=W->AdjV;
			}
		}
	}


}
