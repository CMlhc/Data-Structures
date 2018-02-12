#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};



BinTree CreateBinTree(ElementType Data,int N);
bool IsEmpty(BinTree BT,int N);
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
int TotalNode(BinTree BT);
int GetHright(BinTree BT);


int main()
{
    //Build BinTree
    int n=0;
    printf("Input the number Trees you want to build.\n");
    scanf("%d",&n);
    BinTree BT=CreateBinTree(1,n);
    printf("Inorder:\n");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:\n");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:\n");
    PostorderTraversal(BT);
    printf("\n");
    printf("The total nodes is \n");
    printf("%d",TotalNode(BT));
    printf("\n");
    printf("The height of the BinTree is \n");
    printf("%d\n",GetHright(BT));




    return 0;
}

BinTree CreateBinTree(ElementType Data,int N)
{
    BinTree BT;
    BT=(BinTree)malloc(sizeof(struct TNode));
    if(N>1)
    {
      BT->Left=CreateBinTree(Data*2,N-1);
      BT->Right=CreateBinTree(Data*2+1,N-1);
    }else
    {
      BT->Left=NULL;
      BT->Right=NULL;
    }

    BT->Data=Data;

    return BT;
}

bool IsEmptyt(BinTree BT)
{
    if(BT==NULL)
    {
        return true;
    }else
    {
        return false;
    }
}

void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf("%d ",BT->Data);
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%d ",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}


void PostorderTraversal(BinTree BT)
{
    if(BT)
    {
        PostorderTraversal(BT->Right);
        printf("%d ",BT->Data);
        PostorderTraversal(BT->Left);
    }
}

int TotalNode(BinTree BT)
{
    if(BT)
    {
        return 1+TotalNode(BT->Left)+TotalNode(BT->Right);
    }else
    {
        return 0;
    }

}

int GetHright(BinTree BT)
{
    int HL,HR,MAX;
    if(BT)
    {
        HL=GetHright(BT->Left);
        HR=GetHright(BT->Right);
        MAX=HL>HR?HL:HR;
        return MAX+1;
    }else
    {
        return 0;
    }
}
