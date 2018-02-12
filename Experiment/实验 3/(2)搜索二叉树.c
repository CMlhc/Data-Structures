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



BinTree CreateBinTree(ElementType Data);
bool IsEmpty(BinTree BT,int N);
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
int TotalNode(BinTree BT);
int GetHright(BinTree BT);

BinTree Insert(BinTree BST,ElementType X);


int main()
{
    //Build BinTree
    int n=0;
    int arr[100]={0};
    BinTree BST=NULL;
    printf("请输你想加入节点的个数 :\n");
    scanf("%d",&n);

    int j;
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);

    }
    for(j=0;j<n;j++)
    {
      BST=Insert(BST,arr[j]);
    }


    printf("Inorder:\n");
    InorderTraversal(BST);
    printf("\n");
    printf("Preorder:\n");
    PreorderTraversal(BST);
    printf("\n");
    printf("Postorder:\n");
    PostorderTraversal(BST);
    printf("\n");
    printf("The total nodes is \n");
    printf("%d",TotalNode(BST));
    printf("\n");
    printf("The height of the BinTree is \n");
    printf("%d\n",GetHright(BST));




    return 0;
}

BinTree Insert(BinTree BST,ElementType X)
{
    if(!BST)
    {
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
    }else
    {
        if(X<BST->Data)
            BST->Left=Insert(BST->Left,X);
        if(X>BST->Data)
            BST->Right=Insert(BST->Right,X);
    }
    return BST;
}

BinTree CreateBinTree(ElementType Data)
{
    BinTree BT;
    BT=(BinTree)malloc(sizeof(struct TNode));
    BT->Left=NULL;
    BT->Right=NULL;
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
