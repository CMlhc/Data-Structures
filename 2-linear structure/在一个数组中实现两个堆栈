#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int Position;
typedef int ElementType;

typedef struct SNode* PtrToNode;
struct SNode{
	ElementType *Data;
	Position Top1;
	Position Top2;
	int MaxSize;
};


typedef PtrToNode Stack;


Stack CreateStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S,ElementType X,int Tag);
bool IsEmpty(Stack S);
ElementType Pop(Stack S,int Tag);



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
	int Tag;
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
			printf("Input the X and Tag\n");
			
			scanf("%d %d",&X,&Tag);
			
			if(Push(S,X,Tag))
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
			printf("Input the Tag\n");
			scanf("%d",&Tag);
			printf("%d",Pop(S,Tag));
			break;
			
	}	
	}
	
	
	
	
	return 0;
}


Stack CreateStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
	S->Top1=-1;
	S->Top2=MaxSize;
	S->MaxSize=MaxSize;
	return S;
}


bool IsFull(Stack S)
{
	return (S->Top1+1==S->Top2);
}

bool Push(Stack S,ElementType X,int Tag)
{
	if(IsFull(S))
	{
		printf("ERROR!\n");
		return false;
	}else
	{
		if(Tag==1)
		{
			S->Data[++(S->Top1)]=X;
			return true;	
		}
		
		if(Tag==2)
		{
			S->Data[--(S->Top2)]=X;
			return true;
		}
		
	}
}

bool IsEmpty(Stack S)
{
	return (S->Top1==-1&&S->Top2==S->MaxSize);
	
}


ElementType Pop(Stack S,int Tag)
{
	if(IsEmpty(S))
	{
		printf("ERROR\n");
		return false;
	}else
	{
		if(S->Top1!=-1&&Tag==1)
		{
			return (S->Data[(S->Top1)--]);
		}
		
		if(S->Top2!=S->MaxSize&&Tag==2)
		{
			return (S->Data[(S->Top1)++]);
		}
		
	}
}
