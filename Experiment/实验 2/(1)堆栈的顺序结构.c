#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int Position;
typedef int ElementType;

typedef struct SNode* PtrToNode;
struct SNode{
	ElementType *Data;
	Position Top;
	int MaxSize;
};


typedef PtrToNode Stack;


Stack CreateStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S,ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);



int main()
{
	printf("1:Stack CreateStack(int MaxSize);\n");
	printf("2:bool IsFull(Stack S);\n");
	printf("3:bool Push(Stack S,ElementType X);\n");
	printf("4:bool IsEmpty(Stack S);\n");
	printf("5:ElementType Pop(Stack S);\n");
	Stack S;
	int n;
	int X;
	while(1)
	{
	scanf("%d",&n);
	switch(n)
	{
		case 1:

			printf("Input the MaxSize:\n");
			int Max;
			scanf("%d",&Max);
			S=CreateStack(Max);
			break;
		case 2:
			if(IsFull(S))
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
			break;
		case 3:
			printf("Input the X\n");

			scanf("%d",&X);

			if(Push(S,X))
			{
				printf("sucess\n");
			}else
			{
				printf("fail\n");
			}
			break;
		case 4:
			if(IsEmpty(S))
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
			break;
		case 5:
			printf("%d",Pop(S));
			break;

	}
	}




	return 0;
}


Stack CreateStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
	S->Top=-1;
	S->MaxSize=MaxSize;
	return S;
}


bool IsFull(Stack S)
{
	return (S->Top==S->MaxSize-1);
}

bool Push(Stack S,ElementType X)
{
	if(IsFull(S))
	{
		printf("ERROR!\n");
		return false;
	}else
	{

		S->Data[++(S->Top)]=X;
		return true;
	}
}

bool IsEmpty(Stack S)
{
	return (S->Top==-1);
}


ElementType Pop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("ERROR\n");
		return false;
	}else
	{
		return (S->Data[(S->Top)--]);
	}
}
