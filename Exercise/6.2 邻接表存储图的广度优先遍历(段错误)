#include<malloc.h>

struct QNode
{
	int *data;
	int front, rear;
	int MaxSize;
};

typedef struct QNode* PtrToQNode;
typedef PtrToQNode Queue;

Queue CreateQueue(int Size)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->data = (int*)malloc(sizeof(int)*Size);
	Q->front = Q->rear = 0;
	Q->MaxSize = Size;

	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->front == Q->rear);
}

bool AddQ(Queue Q, int X)
{
	Q->rear = (Q->rear + 1) % Q->MaxSize;
	Q->data[Q->rear] = X;
	return true;
}

int DeleteQ(Queue Q)
{
	Q->front = (Q->front + 1) % Q->MaxSize;
	return Q->data[Q->front];
}

void BFS(LGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	Queue Q;
	PtrToAdjVNode W;
	int V;

	Visit(S);
	Visited[S] = true;

	AddQ(Q, S);
	while (!IsEmpty(Q))
	{
		V = DeleteQ(Q);
		for (W = Graph->G[V].FirstEdge; W;W=W->Next)
		{
			if (!Visited[W->AdjV])
			{
				Visit(W->AdjV);
				Visited[W->AdjV] = true;
				AddQ(Q, W->AdjV);
			}

		}

	}

}
