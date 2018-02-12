#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define ERROR -1

typedef int Position;
typedef int ElementType;
typedef struct SNode * PtrToSNode;
struct SNode{
    ElementType Data;
    PtrToSNode Next;

};

typedef PtrToSNode Stack;

Stack CreateStack();

bool Push(Stack S,ElementType X);
bool IsEmpty(Stack S);
ElementType Pop(Stack S);

int main()
{
    printf("堆栈的链式实现\n");
	printf("1:bool Push(Stack S,ElementType X);\n");
	printf("2:bool IsEmpty(Stack S);\n");
	printf("3:ElementType Pop(Stack S);\n");
	Stack S=CreateStack();
	int n;
	int X;
	while(1)
	{
	scanf("%d",&n);
	switch(n)
	{


		case 1:
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
		case 2:
			if(IsEmpty(S))
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
			break;
		case 3:
			printf("%d",Pop(S));
			break;

	}
	}






    return 0;
}



Stack CreateStack()
{
    Stack S;
    S=malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Next==NULL);
}

bool Push(Stack S,ElementType X)
{
    PtrToSNode TmpCell;

    TmpCell=(PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data=X;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
    return true;
}

ElementType Pop(Stack S)
{
    PtrToSNode FirstCell;
    ElementType TopElem;

    if(IsEmpty(S))
    {
        printf("堆栈空\n");
        return ERROR;
    }
    else
    {
        FirstCell=S->Next;
        TopElem=FirstCell->Data;
        S->Next=FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }


}
