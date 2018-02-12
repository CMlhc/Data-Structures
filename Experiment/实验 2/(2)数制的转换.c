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
void conversion(Stack S,int N,int d);


int main()
{
    while(1)
    {
     printf("请输入你想要转换的数以及你要转换的进制:\n");
     Stack S=CreateStack(100);
     int N,d;
     scanf("%d%d",&N,&d);
     conversion(S,N,d);
     system("pause");
     system("cls");
    }


	return 0;
}

void conversion(Stack S, int N, int d)
{
    int mod;
    int q=N;
    while(N!=0){
        mod=N%d;
        Push(S,mod);
        N=N/d;
    }


    printf("将10进制的%d转换为%d进制后为  ",q,d);
    while(!IsEmpty(S))
    {

        printf("%d",Pop(S));
    }
    printf("\n\n\n");
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
		//printf("ERROR!\n");
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
		//printf("ERROR\n");
		return false;
	}else
	{
		return (S->Data[(S->Top)--]);
	}
}
