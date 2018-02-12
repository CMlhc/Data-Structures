#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define INFINITY 1e9


typedef int Position;
typedef double ElementType;
typedef enum{num, opr ,end}Type;

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
Type GetOp(char *Expr,int * start,int *str);
ElementType PostfixExp(char *Expr);




int main() 
{
	char Expr[MAXOP];
	ElementType f;
	
	gets(Expr);
	f=PostfixExp(Expr);
	
	if(f<INFINITY)
	{
		printf("%.4f\n",f);
	}else
	{
		printf("ERROR\n");
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

Type GetOp(char *Expr,int* start,char *str)
{
	int i=0;
	
	while((str[0]=Expr[(*start)++])==' ');
	
	while(str[i]!=' '&&str[i]!='\0')
		str[++i]=Expr[(*start)++];
	if(str[i]=='\0')
		(*start)--;
		
	if(i==0) return end;
	else if(isdigit(str[0])||isdigit(str[1])) return num;
	else return opr;
}

ElementType PostfixExp(char* Expr)
{
	Stack S;
	Type T;
	ElementType Op1,Op2;
	char str[MAXOP];
	int start=0;
	
	S=CreateStack(MAXOP);
	Op1=Op2=0;
	
	while((T=GetOp( Expr,&start,str))!=end)
	{
		if(T==num)
		{
			Push(S,atof(str));
		}else
		{
			if(!IsEmpty(S)) Op2=Pop(S);
			else Op2=INFINITY;
			
			if(!IsEmpty(S)) Op1=Pop(S);
			else Op2=INFINITY;
			
			switch(str[0])
			{
				case '+':
					Push(S,Op1+Op2);
					break;
				case '-':
					Push(S,Op1-Op2);
					break;
				case '*':
					Push(S,Op1*Op2);
					break;
				case '/':
					if(Op2!=0)
					{
						Push(S,Op1/Op2);	
					}else{
						printf("ERROR\n");
						Op2=INFINITY;
					}
					break;
				default:
					printf("ERROR\n");
					Op2=INFINITY;
					break; 
						
			}
			if(Op2>=INFINITY)
				break;
		}
		
	}
	if(Op2<INFINITY)
	{
		if(!IsEmpty(S))
			Op2=Pop(S);
		else
			Op2=INFINITY;
	}
	free(S);
	return Op2;
}
