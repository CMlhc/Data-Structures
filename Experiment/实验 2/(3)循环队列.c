#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define ERROR -1

typedef int Posision;
typedef int ElementType;

typedef struct QNode* PtrToQNode;

struct QNode{
	ElementType *Data;
	Posision Front,Rear;
	int MaxSize;
};

typedef PtrToQNode Queue;


int main()
{
	
	
	
	return 0;
} 

Queue CreateQueue(int MaxSize)
{
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	Q->MaxSize=MaxSize;
	Q->Front=Q->Rear=0;
	return Q;
}

bool IsFull(Queue Q)
{
	return (Q->Rear+1)%Q->MaxSize==Q->Front;
}

bool AddQ(Queue Q,ElementType X)
{
	if(IsFull(Q))
	{
		printf("the queue full\n");
		return false;
	}
	else
	{
		Q->Rear=(Q->Rear+1)%Q->MaxSize;
		Q->Data[Q->Rear]=X;
		return true;
	}
}

bool IsEmpty(Queue Q)
{
	return Q->Front==Q->Rear;
}


ElementType DeleteQ(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("the queue is empty\n");
		return ERROR;
	}else
	{
		Q->Front=(Q->Front+1)%Q->MaxSize;
		return Q->Data[Q->Front];
	}
}
